#ifndef HIP_CUDA_H
#define HIP_CUDA_H

#include <cuda_runtime.h>
#include <helper_cuda.h>
#include <cuda_runtime_api.h>
#include <cuda_gl_interop.h>


#define hipResetDefaultDevice() cudaDeviceReset()
#define hipMalloc(...) cudaMalloc(__VA_ARGS__)
#define hipMemcpy(...) cudaMemcpy(__VA_ARGS__)
#define hipFree(...) cudaFree(__VA_ARGS__)
#define hipMemset(...) cudaMemset(__VA_ARGS__)
#define hipCreateChannelDesc() cudaCreateChannelDesc<float>() // TODO: Implement templates
#define hipMallocPitch(...) cudaMallocPitch(__VA_ARGS__)
#define hipMallocArray(...) cudaMallocArray(__VA_ARGS__)
#define hipMemcpy2D(...) cudaMemcpy2D(__VA_ARGS__)
#define hipMemcpy2DToArray(...) cudaMemcpy2DToArray(__VA_ARGS__)
#define hipBindTextureToArray(...) cudaBindTextureToArray(__VA_ARGS__)
#define hipUnbindTexture(...) cudaUnbindTexture(__VA_ARGS__)
#define hipArray cudaArray
#define hipChannelFormatDesc cudaChannelFormatDesc
#define texture texture<float,2> // TODO: Implement templates
#define hipFilterModePoint cudaFilterModePoint

#define CUDA_SAFE_CALL(x) checkCudaErrors(x)
#define CUT_CHECK_ERROR(x) getLastCudaError(x)

#define __KERNEL __global__

#define HIP_ASSERT(x) \
  assert(!x)

#define hipCreateLaunchParam2(blocks, threads) \
  blocks, threads

#define hipMemcpyHostToDevice cudaMemcpyHostToDevice
#define hipMemcpyDeviceToHost cudaMemcpyDeviceToHost
#define hipMemcpyDeviceToDevice cudaMemcpyDeviceToDevice

#define hipLaunchKernel(kernel, grid, block, ...) \
  grid_launch_parm lp; \
  lp.gridDim.x = grid.x; \
  lp.gridDim.y = grid.y; \
  lp.gridDim.z = grid.z; \
  lp.groupDim.x = block.x; \
  lp.groupDim.y = block.y; \
  lp.groupDim.z = block.z; \
  kernel<<<grid, block>>>(lp, __VA_ARGS__)

#define DIM3(...) dim3(__VA_ARGS__)

#define GRID_LAUNCH_INIT(lp) \
    lp.gridDim.x = gridDim.x; \
    lp.gridDim.y = gridDim.y; \
    lp.gridDim.z = gridDim.z; \
    lp.groupDim.x = blockDim.x; \
    lp.groupDim.y = blockDim.y; \
    lp.groupDim.z = blockDim.z; \
    lp.groupId.x = blockIdx.x; \
    lp.groupId.y = blockIdx.y; \
    lp.groupId.z = blockIdx.z; \
    lp.threadId.x = threadIdx.x; \
    lp.threadId.y = threadIdx.y; \
    lp.threadId.z = threadIdx.z

#define SQRTF(x) sqrtf(x)

#endif