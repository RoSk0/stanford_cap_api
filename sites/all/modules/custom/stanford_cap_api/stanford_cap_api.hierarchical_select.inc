<?php

/**
 * @file
 * Stanford CAP API integration with hierarchical_select module.
 */

/**
 * Implements hook_hierarchical_select_params().
 */
function stanford_cap_api_hierarchical_select_params() {
  return array();
}

/**
 * Implements hook_hierarchical_select_root_level().
 */
function stanford_cap_api_hierarchical_select_root_level() {
  $label = db_select('cap_api_orgs', 'orgs')
    ->condition('orgid', CAP_ROOT_ORGANIZATION_ID)
    ->fields('orgs', array('name'))
    ->execute()
    ->fetchField();
  $label = $label ? check_plain($label) : t('Organizations not imported yet');

  return array(CAP_ROOT_ORGANIZATION_ID => $label);
}

/**
 * Implements hook_hierarchical_select_children().
 */
function stanford_cap_api_hierarchical_select_children($parent) {
  $cache =& drupal_static(__FUNCTION__, array());
  if (!isset($cache[$parent])) {
    $children = db_select('cap_api_orgs', 'orgs')->condition('orgid', $parent)
      ->fields('orgs', array('children'))->execute()->fetchField();
    if (!empty($children)) {
      $children = unserialize($children);
      $children = db_select('cap_api_orgs', 'orgs')
        ->condition('orgid', $children, 'IN')
        ->fields('orgs', array('orgid', 'name'))
        ->execute()
        ->fetchAllKeyed();
      $cache[$parent] = array_map('t', $children);
    }
    else {
      $cache[$parent] = array();
    }
  }

  return $cache[$parent];
}

/**
 * Implements hook_hierarchical_select_lineage().
 */
function stanford_cap_api_hierarchical_select_lineage($orgid) {
  $parents = array();
  $parent = $orgid;
  while ($parent != 0) {
    $parents[] = $parent;
    $parent = db_select('cap_api_orgs', 'orgs')
      ->condition('orgid', $parent)
      ->fields('orgs', array('parent'))
      ->execute()
      ->fetchField();
  }

  return array_reverse($parents);
}

/**
 * Implements hook_hierarchical_select_valid_item().
 */
function stanford_cap_api_hierarchical_select_valid_item($orgid) {
  $cache =& drupal_static(__FUNCTION__, array());
  if (!isset($cache[$orgid])) {
    $cache[$orgid] = db_select('cap_api_orgs', 'orgs')
      ->condition('orgid', $orgid)
      ->fields('orgs', array('orgid'))
      ->execute()
      ->fetchField();
  }

  return $cache[$orgid];
}

/**
 * Implements hook_hierarchical_select_item_get_label().
 */
function stanford_cap_api_hierarchical_select_item_get_label($orgid) {

  $label = db_select('cap_api_orgs', 'orgs')
    ->condition('orgid', $orgid)
    ->fields('orgs', array('name'))
    ->execute()
    ->fetchField();

  return check_plain($label);
}
