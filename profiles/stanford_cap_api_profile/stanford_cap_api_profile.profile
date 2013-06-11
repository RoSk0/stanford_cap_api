<?php

/**
 * @file
 *
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function stanford_cap_api_profile_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = st('Stanford CAP API');
}
