<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('sudoku')) {
	dl('sudoku.' . PHP_SHLIB_SUFFIX);
}
$module = 'sudoku';
$functions = get_extension_funcs($module);
echo "Functions available in the test extension:$br\n";
foreach($functions as $func) {
    echo $func."$br\n";
}
echo "$br\n";
$function = 'confirm_' . $module . '_compiled';
if (extension_loaded($module)) {
	$array = lgenerate_sudoku(1);
	print_r($array);
	$str = count($array);
} else {
	$str = "Module $module is not compiled into PHP";
}
echo "$str\n";
?>
