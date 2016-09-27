<?PHP
/*
PHP CMD script to assemble the different chapters into a single HTML page
*/

$output = "Documentation.html";
$content = '';
$menu_content = '';
$_files = New FilesystemOperations;

// get list of .html files in current directory
$filter = array( '.html' );
$_files->set_ls_filter($filter);
$_files->set_ls_filter_mode('include');
$list = $_files->ls('./');


// load outer shell first
$outer_shell = file_get_contents('1_Main_Menu.html')."\n";


// get pages
foreach( $list as $val ){
	if( file_exists($val) && $val !== '1_Main_Menu.html' && $val !== $output )
	{
		$page = file_get_contents($val)."\n";
		$menu_list[] = get_menu_entry($page);
		$content .= $page;
	}
}


//build menu
foreach( $menu_list as $menu ){
	$menu_content .= "<a href=\"#{$menu['anchor']}\">{$menu['label']}</a><br>\n";
}


$outer_shell = str_replace( '<!--MAIN_MENU_CONTENT-->', $menu_content, $outer_shell );
$outer_shell = str_replace( '<!--PAGE_CONTENT-->', $content, $outer_shell );
file_put_contents( $output, $outer_shell );





// retrieve value for data-menu from first line
// <div id="ank_push_button_specs" data-menu="Push Button Sources and Specifications">
// returns array['label'] && array['anchor']
function get_menu_entry( &$content ){
	$ret = array();
	
	$matches = array();
	preg_match( '/data-menu=\"(.*?)\"/i', $content, $matches);
	$ret['label'] = $matches[1];

	
	$matches = array();
	preg_match( '/id=\"(.*?)\"/i', $content, $matches);
	$ret['anchor'] = $matches[1];
	

	return $ret;
}




/**
 * class to handle file operations
 */
class FilesystemOperations{

  private $filter_file;
  private $filter_mode;
  private $filter_partial;
  private $dir_slash;
  var $ls_output;

  public function __construct()
  {
    $this->filter_file = array();
    $this->filter_mode = 'exlude';
    $this->filter_partial = 2;
    $this->ls_output = '';
    if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN'){
      $this->dir_slash = '\\';
    }else{
      $this->dir_slash = '/';
    }
  }

  /**
   * method to change slashes in a path so they match the OS
   * @param type $path
   * @return nothing, works by reverence
   */
  public function fix_slash( &$path ){
    if( $this->dir_slash !== '/' || $this->dir_slash !== '\\'){
      if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN'){
        $this->dir_slash = '\\';
      }else{
        $this->dir_slash = '/';
      }
    }

    //time to fix
    if( $this->dir_slash === '/'){
      $path = str_replace( '\\', '/', $path);
    }else{
      $path = str_replace( '/', '\\', $path);
    }

  }

  /**
   * reads the contents of a file specified as string
   * @param string $file_with_path filename with path
   * @return bool,string string containing text of boolean false of error
   */
  public function readfile( $file_with_path )
  {
    clearstatcache();
    if( !file_exists($file_with_path) ){ return false; }
    $handle = fopen($file_with_path, "r");
    $contents = @fread($handle, filesize($file_with_path));
    if( $contents === false ) {
      echo "Error reading file: $file_with_path\r\n";
      return false;
    }
    fclose($handle);
    return $contents;
  }

  public function writefile( &$file_with_path, &$file_content )
  {
    $handle=fopen($file_with_path,"wb");
    fwrite($handle, $file_content);
    fclose($handle);
    return true;
  }

  /**
   * function to specify a file filter for ls
   * @param array $filter array containg strings to filter array('.php','.js')
   * @param int $partial if 0 then filter will do a full name match<br>if 1 filter will do a partial match<br>if 2 filter will do an extension match
   * @return boolean true on sucess or false on failure
   */
  public function set_ls_filter( &$filter, $partial = 2 )
  {
    if( is_array($filter) ){
      $this->filter_file = $filter;
    }else
      return false;

    switch($partial){
      case 0:
        $this->filter_partial = 0;
        break;
      case 1:
        $this->filter_partial = 1;
        break;
      case 2:
        $this->filter_partial = 2;
        break;
      default:
        $this->filter_partial = 2;
        break;
    }
  }

  /**
   * sets the filter mode for ls_filter
   * @param string $mode 'exlude' = don't add files matching the filter OR 'include' = only add file matching the filter
   * @return boolean true on sucess or false on failure
   */
  public function set_ls_filter_mode( $mode = 'exlude')
  {
    switch($mode)
    {
      case 'exlude':
        $this->filter_mode = 'exclude';
        return true;
      case 'include':
        $this->filter_mode = 'include';
        return true;
      default:
        return false;
    }
  }

  /**
  * list all files and directories within anoher
  * @param string $dir start path as string
  * @param bool $prefix=false set to true to add the directory path to the output
  * @param string $pref_strip pass a string to be stripped from the returned paths. useful for home dirs
  * @return array returns array with one file per key
  */
  public function ls($dir, $prefix=false, $pref_strip = '')
  {
    if(is_dir($dir) !== true ) return false;
    $filter_cnt = count($this->filter_file); //don't filer if zero
    $this->ls_output = ''; //clear old info

    $handle = opendir($dir);
    $ret = array();
    if($handle)
    {
      /* This is the correct way to loop over the directory. */
      while (false !== ($file = readdir($handle))) {
        if( $file !== '.' && $file !== '..')
        {
          if( is_dir($dir.$this->dir_slash.$file) === true ){
            if( $pref_strip === '' )
              $ret_tmp = $this->ls($dir.$this->dir_slash.$file, true);
            else
              $ret_tmp = $this->ls($dir.$this->dir_slash.$file, true, $dir);
            if( is_array($ret_tmp) === true ) $ret = array_merge($ret, $ret_tmp);
          }else{
            if( $prefix === true){
              if( $pref_strip === '' ){

                //store name and check if it needs to be filtered
                $pass = $dir.$this->dir_slash.$file;
                if( $filter_cnt > 0 ){
                  //check if the name shold be filtered out
                  if( $this->ls_filter($pass) === true )
                    $ret[] = $pass;
                }else
                  $ret[] = $pass;

              }else{
                //Strip by string length
                $slen = strlen($pref_strip);
                $tmp = substr($dir, $slen).$this->dir_slash.$file; //get everything after the prefix
                $tmp = ltrim($tmp, $this->dir_slash); //remove leading slash so it matches the UI

                if( $filter_cnt > 0 ){
                  //check if the filename is legal
                  if( $this->ls_filter($tmp) === true )
                    $ret[] = $tmp;
                }else
                  $ret[] = $tmp;
              }

            }else{
              if( $filter_cnt > 0 ){
                //check if the filename is legal
                if( $this->ls_filter($file) === true )
                  $ret[] = $file;
              }else
                $ret[] = $file;
            }
          }
        }
      }
      closedir($handle);
    }
    //sort($ret);
    $this->ls_output = $ret;
    return $ret;
  }

/**
 * deletes files and directories, think rm -rf $dir
 * @param string $dir path to be deleted
 */
function rm($dir)
{
  //delete a single file?
  if(is_dir($dir) !== true ){
    @unlink($dir);
    return true;
  }

  //Do a few basic checks
  if( $dir == '' || $dir == '/' || $dir == '.' || $dir == '..' ) return false;

  $handle = opendir($dir);
  if($handle)
  {
      //Delete all files first
      while (false !== ($file = readdir($handle))) {
          if( $file !== '.' && $file !== '..')
          {
              if( is_dir("$dir{$this->dir_slash}$file") === true ){
                  //Try to delete the directory. Assume that it is not empty on failure and enter it
                  if( @rmdir("$dir{$this->dir_slash}$file") !== true ){
                      $this->rm("$dir{$this->dir_slash}$file");
                  }
              }else{
                  @unlink("$dir{$this->dir_slash}$file"); //delete a single file
              }
          }
      }
      closedir($handle);
  }

  $handle = opendir($dir);
  if($handle)
  {
      //Second run, delete all empty directories
      while (false !== ($file = readdir($handle))) {
          if( $file !== '.' && $file !== '..')
          {
              if( is_dir("$dir{$this->dir_slash}$file") === true ){
                  //Try to delete the directory. Assume that it is not empty on failure and enter it
                  if( @rmdir("$dir{$this->dir_slash}$file") !== true )
                     $this->rm("$dir{$this->dir_slash}$file");
              }
          }
      }
      closedir($handle);
  }

  //and finally, delete $dir as well
  rmdir($dir);
}

  /**
   * method to apply a filter to the ls output
   * @param type $file
   * @return boolean true if the file does NOT match a filter contidion or false if it does
   */
  private function ls_filter( &$file )
  {
    if( !is_array($this->filter_file) ) return false;

    foreach( $this->filter_file as $ff )
    {
      //partial, full match or extension match?
      if( $this->filter_partial === 0 )
      {
        //full match
        if( $file === $ff ){
          //include or exclude the file
          if( $this->filter_mode === 'exlude' )
            return false;
          else
            return true;
        }
      }elseif( $this->filter_partial === 1 ){
        //partial match
        if( strpos($file, $ff) !== false  ){
          //include or exclude the file
          if( $this->filter_mode === 'exlude' )
            return false;
          else
            return true;
        }
      }elseif( $this->filter_partial === 2 ){
        //extension match
        $part = substr($file, (strlen($file)-strlen($ff)));
        if( $part === $ff ){
          //include or exclude the file
          if( $this->filter_mode === 'exlude' )
            return false;
          else
            return true;
        }
      }
    }
  }

  /**
   * method for copying files recursivly, with support for creating any necessary subdirs
   *  it is supposed to work like this: mkdir -p $(dirname "bar"); cp -r "foo" "bar"
   *
   * @param string $src source file or directory
   *                      <ul>
   *                        <li>copy will be recursive if you pass a dir</li>
   *                        <li>must end with a slash if source is a file but destination is a directory</li>
   *                      <ul>
   * @param string $dest destination file or directory
   *                      <ul>
   *                        <li>must be a directory if source if one as well</li>
   *                        <li>must end with a slash if source is a file but destination is a directory</li>
   *                      <ul>
   * @param integer $chmod=0700 chmod of copied files and created directories
   * @param string $chown setting this option will attempt to change the owner on the destination side
   */
  function cp( $src, $dest, $chmod = 0700, $chown=null ){
    $debug = false;
    //ensure slashes are proper
    $this->fix_slash($src);
    $this->fix_slash($dest);

    if( !is_dir($src) && !is_file($src) ){
      echo "\nSource does not exist: $src\n";
      return false;
    }

    if( is_dir( $src ) ){
      //recursive file copy
      if( !is_dir($dest) && !is_file($dest) ){
        mkdir( $dest, $chmod, true);

        if( $handle = opendir($src) ){
            if( $debug !== false ){
              echo "\nDirectory handle: $handle";
              echo "\nEntries:";
            }

            /* This is the correct way to loop over the directory. */
            while( false !== ($entry = readdir($handle)) ){
               if ($entry != "." && $entry != "..") {
                 //echo "\nNOT IMPLEMENTED!! -- $entry";
                 //copy($src, $dest);
                 $this->fix_slash($entry);
                 $this->cp( $src.$this->dir_slash.$entry, $dest.$this->dir_slash.$entry, $chmod, $chown);
               }
            }

            closedir($handle);
        }
      }
    }else{
      //single file copy

      //check if $dest exists
      if( !is_file($dest) ){
        //does not, check if $dst is a dir and create it if it is
        if( !is_dir($dest) && substr( $dest, (strlen($dest)-1) ) === $this->dir_slash ){
          //it is a dir and does not exist, create
          mkdir($dest, $chmod, true);
          if( $chown !== null ){ chown($dest, $chown); }

          //copy needs a destination file name so get it from $src
          $parts = explode( $this->dir_slash, $src);
          $c = count($parts);
          $dest .= $parts[$c-1]; //add last part to $dest to get filename

          copy($src, $dest);
          chmod($dest, $chmod);
          if( $chown !== null ){ chown($dest.$parts[$c], $chown); }
          if( $debug !== false ){ echo "\ncopied one file to new dir\n"; }
        }else{ //does not end in a slash, try to copy the file with new name on destination side

          //check if the target sub dir exists
          $parts = explode( $this->dir_slash, $dest);
          $c = count($parts)-1;
          $dest_folder = '';
          for($x = 0 ; $x < $c ; ++$x ){
            if( $parts[$x] != '' ){
              $dest_folder .= $this->dir_slash.$parts[$x];
            }
          }

          if (strtoupper(substr(PHP_OS, 0, 3)) === 'WIN'){
            //never notice the issue of the slash on the left under Linux so only apply to Windows for now
            $dest_folder = ltrim($dest_folder, '\\');
          }
          
          if( !is_dir($dest_folder) ){
            mkdir($dest_folder, $chmod, true);
            if( $chown !== null ){ chown($dest_folder, $chown); }
          }

          //compres dest and $dest_fodler
          // add filename to $dest if they are the same so copy() works
          if( $dest == $dest_folder || $dest == $dest_folder.$this->dir_slash ){
            //add last part of $parts to dest
            $sparts = explode( $this->dir_slash, $src);
            $sc = count($sparts)-1;
            $dest .= $sparts[$sc];
          }

          copy($src, $dest);
          chmod($dest, $chmod);
          if( $chown !== null ){ chown($dest, $chown); }
          if( $debug !== false ){ echo "\ncopied one file with same name\n"; }
        }
      }else{
        if( $debug !== false ){ echo "\ndestination already exists: $dest\n"; }
      }


    }

  }

} //class
?>