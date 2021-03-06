#ifndef ROUTE_LAYER_H
#define ROUTE_LAYER_H
#include "network.h"
#include "cuda.h"
#include "layer.h"
#include "connected_layer.h"
#include "blas.h"
#include "gemm.h"
#include "activation_layer.h"
#include "avgpool_layer.h"

typedef layer route_layer;

route_layer make_route_layer(int batch, int n, int *input_layers, int *input_size, int *out_chnel, int w, int h);
void forward_route_layer(const route_layer l, network net);
void backward_route_layer(const route_layer l, network net);
void resize_route_layer(route_layer *l, network *net);

#ifdef GPU
void forward_route_layer_gpu(route_layer l, network net);
void backward_route_layer_gpu(route_layer l, network net);
void update_route_layer_gpu(layer l, update_args a);
#endif
void pull_route_layer(layer l);
void push_route_layer(layer l);
#endif
