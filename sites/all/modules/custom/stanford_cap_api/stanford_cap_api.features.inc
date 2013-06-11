<?php
/**
 * @file
 * stanford_cap_api.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_cap_api_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function stanford_cap_api_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function stanford_cap_api_node_info() {
  $items = array(
    'cap_faculty_profile' => array(
      'name' => t('Faculty profile'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
