<?php
/**
 * @file
 * stanford_cap_api_orgs.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function stanford_cap_api_orgs_taxonomy_default_vocabularies() {
  return array(
    'stanford_org_code_hierarchy' => array(
      'name' => 'Stanford University Org Code Hierarchy',
      'machine_name' => 'stanford_org_code_hierarchy',
      'description' => NULL,
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
