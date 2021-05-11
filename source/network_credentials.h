/******************************************************************************
* File Name: network_credentials.h
*
* Description: This file is the public interface for Wi-Fi credentials and
* TCP server certificate.
*
* Related Document: See README.md
*
*******************************************************************************
* Copyright 2019-2021, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

/*******************************************************************************
* Include guard
*******************************************************************************/
#ifndef NETWORK_CREDENTIALS_H_
#define NETWORK_CREDENTIALS_H_

#include "cy_wcm.h"

/*******************************************************************************
* Macros
********************************************************************************/
#define INITIALISER_IPV4_ADDRESS(addr_var, addr_val)   addr_var = { CY_WCM_IP_VER_V4, \
                                                       { .v4 = (uint32_t)(addr_val) } }

#define MAKE_IPV4_ADDRESS(a, b, c, d)                  ((((uint32_t) d) << 24) | \
                                                       (((uint32_t) c) << 16) | \
                                                       (((uint32_t) b) << 8) | \
                                                       ((uint32_t) a))

/* To use the Wi-Fi device in AP interface mode, set this macro as '1' */
#define USE_AP_INTERFACE                               (0)

#if(USE_AP_INTERFACE)
    #define WIFI_INTERFACE_TYPE                        CY_WCM_INTERFACE_TYPE_AP
    /* SoftAP Credentials: Modify SOFTAP_SSID and SOFTAP_PASSWORD as required */
    #define SOFTAP_SSID                                "MY_SOFT_AP"
    #define SOFTAP_PASSWORD                            "psoc1234"

    /* Security type of the SoftAP. See 'cy_wcm_security_t' structure
     * in "cy_wcm.h" for more details.
     */
    #define SOFTAP_SECURITY_TYPE                       CY_WCM_SECURITY_WPA2_AES_PSK

    #define SOFTAP_IP_ADDRESS_COUNT                    (2u)

    #define SOFTAP_IP_ADDRESS                          MAKE_IPV4_ADDRESS(192, 168, 10, 1)
    #define SOFTAP_NETMASK                             MAKE_IPV4_ADDRESS(255, 255, 255, 0)
    #define SOFTAP_GATEWAY                             MAKE_IPV4_ADDRESS(192, 168, 10, 1)
    #define SOFTAP_RADIO_CHANNEL                       (1u)
#else
    #define WIFI_INTERFACE_TYPE                        CY_WCM_INTERFACE_TYPE_STA
    /* Wi-Fi Credentials: Modify WIFI_SSID, WIFI_PASSWORD, and WIFI_SECURITY_TYPE
     * to match your Wi-Fi network credentials.
     * Note: Maximum length of the Wi-Fi SSID and password is set to
     * CY_WCM_MAX_SSID_LEN and CY_WCM_MAX_PASSPHRASE_LEN as defined in cy_wcm.h file.
     */
    #define WIFI_SSID                                  "MY_WIFI_SSID"
    #define WIFI_PASSWORD                              "MY_WIFI_PASSWORD"

    /* Security type of the Wi-Fi access point. See 'cy_wcm_security_t' structure
     * in "cy_wcm.h" for more details.
     */
    #define WIFI_SECURITY_TYPE                         CY_WCM_SECURITY_WPA2_AES_PSK

    /* Maximum number of connection retries to a Wi-Fi network. */
    #define MAX_WIFI_CONN_RETRIES                      (10u)

    /* Wi-Fi re-connection time interval in milliseconds */
    #define WIFI_CONN_RETRY_INTERVAL_MSEC              (1000u)
#endif

/* TCP server certificate. Copy from the TCP server certificate
 * generated by OpenSSL (See Readme.md on how to generate a SSL certificate).
 */
#define keySERVER_CERTIFICATE_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDZTCCAk2gAwIBAgIUYTurIbRavv6y4BAl0hmPOnhb9pUwDQYJKoZIhvcNAQEL\n"\
"BQAwQjELMAkGA1UEBhMCWFgxFTATBgNVBAcMDERlZmF1bHQgQ2l0eTEcMBoGA1UE\n"\
"CgwTRGVmYXVsdCBDb21wYW55IEx0ZDAeFw0yMTAzMDgxODE1NTlaFw0zMTAzMDYx\n"\
"ODE1NTlaMEIxCzAJBgNVBAYTAlhYMRUwEwYDVQQHDAxEZWZhdWx0IENpdHkxHDAa\n"\
"BgNVBAoME0RlZmF1bHQgQ29tcGFueSBMdGQwggEiMA0GCSqGSIb3DQEBAQUAA4IB\n"\
"DwAwggEKAoIBAQC0jeZ0ZDhs+ouft9usb5nl+t4hEhnsfpAvm8u0CGTPjeL6IshQ\n"\
"BDgm4ZaTwlUP53oqUDosyY5kTsUCBYJy7Yk8maNam5+BBeUx+ekHjT7Rh/0NUyaJ\n"\
"QQMNGrk5tlJ0Pp97Fk0m5G/bETGLHfMwOzbFcUqjYPuvGupXXEbwOUie6IxP+INy\n"\
"9/UqhOscreFFx/+rGrgV2Iy/cqZ7NSxKO/MVDOAfqx9LZEPSUQsVaL05m+ee9cuw\n"\
"Gz4Brdkjnx6gtVSLjhNXXX9wm6VDXwCqlmKLtWdFgtaBEurNn3m2MtevXDWO6qqa\n"\
"A6/l55Jo8LZuNY7uy/mUT2STLj743mT9bXNhAgMBAAGjUzBRMB0GA1UdDgQWBBTp\n"\
"BhJiLQW4bQVjhNlRgNIxNKtlzjAfBgNVHSMEGDAWgBTpBhJiLQW4bQVjhNlRgNIx\n"\
"NKtlzjAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQCen1QWpAzy\n"\
"WjbSeLVSMrhodrZ2zRqEc/l6LLhzLiKbWg4kWOvaLNRy08UNlFZ8LdZYAMt04W0K\n"\
"ZEJ5q6rUKQJlDKnnrb3+14/bLXDu8Z6DbPLyBhIsNmYnfGZKPNcUZuK/C0hYBXi6\n"\
"EVebi41n8Tqla+/jSEe7pRb2hDVlT46ZKNG0cznUFdql+579WJwnHEHksE8sCXDY\n"\
"SoGdfWEyXfVyp1Rf+oX297olnasRavGX3mqz5eTcHGWDS33XaIGi1ivbCtbTDVIU\n"\
"koiLdkF8KwgP7PRMJiMQ97g/dCfz2lGhDrAiyIG/QHgzC98Pe1UGThz8kg7RMVM0\n"\
"dMxfCbjv1//9\n"\
"-----END CERTIFICATE-----\n"

/* Private key of the TCP Server. Copy from the TCP server key 
 * generated by OpenSSL (See Readme.md on how to create a private key).
 */
#define keySERVER_PRIVATE_KEY_PEM \
"-----BEGIN PRIVATE KEY-----\n"\
"MIIEvwIBADANBgkqhkiG9w0BAQEFAASCBKkwggSlAgEAAoIBAQC0jeZ0ZDhs+ouf\n"\
"t9usb5nl+t4hEhnsfpAvm8u0CGTPjeL6IshQBDgm4ZaTwlUP53oqUDosyY5kTsUC\n"\
"BYJy7Yk8maNam5+BBeUx+ekHjT7Rh/0NUyaJQQMNGrk5tlJ0Pp97Fk0m5G/bETGL\n"\
"HfMwOzbFcUqjYPuvGupXXEbwOUie6IxP+INy9/UqhOscreFFx/+rGrgV2Iy/cqZ7\n"\
"NSxKO/MVDOAfqx9LZEPSUQsVaL05m+ee9cuwGz4Brdkjnx6gtVSLjhNXXX9wm6VD\n"\
"XwCqlmKLtWdFgtaBEurNn3m2MtevXDWO6qqaA6/l55Jo8LZuNY7uy/mUT2STLj74\n"\
"3mT9bXNhAgMBAAECggEANZF0MkwZwZuEGVr/PeXOj0Ei7kTklBnoxXc/tKZY4ouC\n"\
"MBxpufPGhSKg/i3F9vYCdNNgrzENog0MvlDMJzT6ZpRett89L5aELZOr46WwYZIr\n"\
"Lezhng8/zH+FPO4vAHYj8uzm7wcPeLtdK50zLbgjw+ic8GQxx/4AUPL7yQH13c85\n"\
"TGlt+hsRwNtFRqlrYcue170/xTUGhS+RngHV2Q0D8prqpRX3kgxRPpSq6IeyBoZo\n"\
"YrjqAvgVmgyMCXHk4Zcl7E9prGUHuP/hJmicLuXEMzCQW72ln0ylo753wFAOumDi\n"\
"6HhPfjAmMhQksM0wMylomD4kmv09rFSAveu3+mwjEQKBgQDeaI8u8xQirIdrqQyP\n"\
"/i2wU1SRpHW6mHD1aOFuQ76Cx4BWJeFMgCNuQPyTRu+zTfwze6eO67iyyvFmnB45\n"\
"Ot0gBfF9CR6J9tNUqmapUm4/wc08PqLF7TWBm2w3+OXIkSjs220eumgh+R0P3O0l\n"\
"IuAbRWffL17ceQsmiyu0v7BhMwKBgQDP0wwVTw57YwNDSKxnF8wEMx5ecfRwzNF3\n"\
"mCdZMDcDgQRH1GOKieYM/BuEvwIJeEiqEG9M/TwJ8rfxh19sfOk42PYXBObnLVHK\n"\
"2nYEJEHLkH42xFWKUw7nHFfdbjO9gl9YzGkqdvgHBeGKVCpQq72SZVAh25FA7qkc\n"\
"gR/+eMYBGwKBgQCEfaM2Y8YN9dtiTj1WliOfk7SgYmljtCYue8E3T5HxFGmmaEBz\n"\
"sy3oIzyTe8GVfhKMlNA3esL3d6Ag8UWr8B4EUqYOR11y8J/qIuyvV5Sn1IqvpdyP\n"\
"rgSe5fisy1APkDHiD8FMed1Ix78BUSnQYptAg7MiKHUJP+5dkrCBp2OqMwKBgQDL\n"\
"56kKWze9TgdMg8hLmiic0j7wsWQBLKQ0b//jXRANCw/VHgjQS76AbPbfBr2L5w18\n"\
"doWNh0TaCd/6RTUV73SwRwckzLV0ip2epzt1ktFPViTPvVCkWBveG4wGAPMY9Apy\n"\
"yJRCitmNonKI0011OxvTwD2gCpr4l3ErO3HVrk+vkwKBgQC9MjlJ3O4YjrKj1y1l\n"\
"WDvEOWjLpQnvETV4KJbs4zkdnylNj7H41g4/mOMlmh6Y7G7Rb8W5I6eiJHR1uLZQ\n"\
"ZbTjd1LcIw9RB7H3msN6BUEMtTgvUWw8JY531h1VKHSJ2vwJ7fblymptijFDgV3l\n"\
"vnJzvVoqd4eehdRPAGq3c8qQew==\n"\
"-----END PRIVATE KEY-----\n"


/* TCP client certificate. In this example this is the RootCA
 * certificate so as to verify the TCP client's identity. */
#define keyCLIENT_ROOTCA_PEM \
"-----BEGIN CERTIFICATE-----\n"\
"MIIDZTCCAk2gAwIBAgIUKO6YXnSJwxwwd+8shCmKl/6xjuIwDQYJKoZIhvcNAQEL\n"\
"BQAwQjELMAkGA1UEBhMCWFgxFTATBgNVBAcMDERlZmF1bHQgQ2l0eTEcMBoGA1UE\n"\
"CgwTRGVmYXVsdCBDb21wYW55IEx0ZDAeFw0yMTAzMDgxODE2MjJaFw0zMTAzMDYx\n"\
"ODE2MjJaMEIxCzAJBgNVBAYTAlhYMRUwEwYDVQQHDAxEZWZhdWx0IENpdHkxHDAa\n"\
"BgNVBAoME0RlZmF1bHQgQ29tcGFueSBMdGQwggEiMA0GCSqGSIb3DQEBAQUAA4IB\n"\
"DwAwggEKAoIBAQCyMigNgmZ4Sg8S6/Zpv+2q9qUUaQ/mOmi7pZRr/bklhuQbMwV9\n"\
"OhPMGxk+DKrvloFXwxU5mcuVR1NW6PE+XpIrN3JLROiK4IHOG42QaNcALnNLVnIe\n"\
"RFWZXO1QUp0RRKZYZtQ3Ko652x/5ZIozrBJ8A0UF+T3bAI0zLzeTZYSOazYBGMuQ\n"\
"ngfCF1utSm7v6hW+76JUdGXeJS0tdGW1xuE+gCnro7I5OPezUrFo5+oxzt+P++Fe\n"\
"eId8nAmJYLV+ydS7cN3E9FSlr1iHxtwt8xxe4yPfnGR9gcQdKcaDoELIVPV62xZi\n"\
"+aSh4nhuXOok69JGnkbzgtNKuqnOH2TSaIyhAgMBAAGjUzBRMB0GA1UdDgQWBBSI\n"\
"KU5rPZUXC5SDw1u07tQEE2qULjAfBgNVHSMEGDAWgBSIKU5rPZUXC5SDw1u07tQE\n"\
"E2qULjAPBgNVHRMBAf8EBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQCOADjwu/SX\n"\
"edFWDfzLoBmYzXie093drJrkd1og7pJO7DiFkdnb4u/X6SdWAKc+9QLR8BKmdSRn\n"\
"z4GhmvHC1+ZakFiFAPvwMSqyAQB/jkbdFljrKfkD7Mz3FwDbXrzSwzG+hLJNe/z6\n"\
"S3sA4xpQi+6ivrutzOx7Va+ujaQPX/zAqNQ6WpT1l3mAaqy8NH1fAdsrTrgXphet\n"\
"xrt6xb9usJ9bS1w+56quKAbQ6gF217VqDrX2Rcpbrr+FwdcUWfp/fIo7x0O95Jke\n"\
"r+ni1pO00x0/C0gLnofYtD8CLwht2PDjMj5rsAIepESENEFwod5zebL69nHwzztX\n"\
"rjhYf2JPRV8z\n"\
"-----END CERTIFICATE-----\n"

#endif /* NETWORK_CREDENTIALS_H_ */
