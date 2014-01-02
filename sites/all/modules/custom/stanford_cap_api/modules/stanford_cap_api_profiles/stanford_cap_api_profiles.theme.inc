<?php

/**
 * @file
 * Theme functions.
 */


function theme_stanford_cap_api_profiles_field_tree($variables) {

  $schema_tree = $variables['schema_tree'];

  _stanford_cap_api_profiles_field_tree($schema_tree, $items);


  return theme('item_list', array('type' => 'ul', 'items' => $items));
}

/**
 * Renders fields checkboxes into tree of lists.
 */
function _stanford_cap_api_profiles_field_tree(&$elem, &$items = array()) {

  foreach (element_children($elem) as $key) {
    // Iterating over top level fields.
    $children = element_children($elem[$key]);
    // Have subfields?
    if (!empty($children)) {
      _stanford_cap_api_profiles_field_tree($elem[$key], $subitems);
      $items[$key] = drupal_render($elem[$key]);
      $items[$key] .= theme('item_list', array('type' => 'ul', 'items' => $subitems));
    }
    else {
      $items[] = drupal_render($elem[$key]);
      unset($elem[$key]);
    }
  }
}
