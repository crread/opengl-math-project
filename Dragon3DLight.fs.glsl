
//const vec3 L = vec3(0.0, 0.0, 1.0);
////
////varying vec2 v_texcoords;
////varying vec3 v_normal;
////
////uniform sampler2D u_sampler;
//
////vec3 Diffuse(vec3 MatColor, vec3 N, vec3 L)
////{
////    float Lambert = max( dot(N, L), 0);
////    return MatColor * max(Lambert, 0.0);
////}
//
//void main(void)
//{
////    vec3 diffuseColor = Diffuse(color, v_normal, L);
////    gl_FragColor = vec4(diffuseColor, 1.0);
////    vec4 color = texture2D(u_sampler, v_texcoords);
//    gl_FragColor = vec4(1.0, 1.0, 0, 1.0);
//    return;
//}