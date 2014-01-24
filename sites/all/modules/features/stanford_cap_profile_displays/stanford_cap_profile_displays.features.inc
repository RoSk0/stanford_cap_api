<?php
/**
 * @file
 * stanford_cap_profile_displays.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function stanford_cap_profile_displays_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function stanford_cap_profile_displays_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
