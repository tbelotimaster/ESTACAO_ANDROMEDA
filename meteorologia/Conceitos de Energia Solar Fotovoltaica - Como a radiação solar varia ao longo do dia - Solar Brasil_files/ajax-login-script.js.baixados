jQuery(document).ready(function($) {

    // Perform AJAX login on form submit
    $( 'form#rella-login' ).on('submit', function(e){
        $('form#rella-login p.status').show().text(ajax_login_object.loadingmessage );
        $.ajax({
            type: 'POST',
            dataType: 'json',
            url: ajax_login_object.ajaxurl,
            data: { 
                'action': 'ajaxlogin', //calls wp_ajax_nopriv_ajaxlogin
                'username': $('form#rella-login #username').val(), 
                'password': $('form#rella-login #password').val(), 
                'security': $('form#rella-login #security').val() },
            success: function(data){
				$('form#rella-login p.status').text(data.message);
                if (data.loggedin == true){
					document.location.href = ajax_login_object.redirecturl;
                }
            },
        } );
        e.preventDefault();
    });

});