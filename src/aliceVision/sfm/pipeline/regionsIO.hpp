// This file is part of the AliceVision project.
// Copyright (c) 2016 AliceVision contributors.
// Copyright (c) 2012 openMVG contributors.
// This Source Code Form is subject to the terms of the Mozilla Public License,
// v. 2.0. If a copy of the MPL was not distributed with this file,
// You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#include <aliceVision/types.hpp>
#include <aliceVision/sfm/SfMData.hpp>
#include <aliceVision/feature/ImageDescriber.hpp>
#include <aliceVision/feature/imageDescriberCommon.hpp>
#include <aliceVision/feature/RegionsPerView.hpp>
#include <aliceVision/feature/FeaturesPerView.hpp>

#include <memory>

namespace aliceVision {
namespace sfm {

/**
 * @brief Load Regions (Features & Descriptors) for one view.
 * @param[in] folders The list of featureFolders
 * @param[in] viewId The view id
 * @param[in] imageDescriber The imageDescriber type
 * @return loaded Regions
 */
std::unique_ptr<feature::Regions> loadRegions(const std::vector<std::string>& folders, IndexT viewId, const feature::ImageDescriber& imageDescriber);

/**
 * @brief Load Features for one view.
 * @param[in] folders The list of featureFolders
 * @param[in] viewId The view id
 * @param[in] imageDescriber The imageDescriber type
 * @return loaded Regions (with only features)
 */
std::unique_ptr<feature::Regions> loadFeatures(const std::vector<std::string>& folders, IndexT viewId, const feature::ImageDescriber& imageDescriber);

/**
 * @brief Load Regions (Features & Descriptors) for each view of the provided SfMData container.
 * @param[in,out] regionsPerView
 * @param[in] sfmData The provided SfMData container
 * @param[in] folder The feature Folder
 * @param[in] imageDescriberType The imageDescriber type
 * @param[in] filter To load Regions only for a sub-set of the views contained in the sfmData
 * @return true if the regions are correctlty loaded
 */
bool loadRegionsPerView(feature::RegionsPerView& regionsPerView,
                        const SfMData& sfmData,
                        const std::string& folders,
                        const std::vector<feature::EImageDescriberType>& imageDescriberTypes,
                        const std::set<IndexT>& filter = std::set<IndexT>());

/**
 * @brief Load Features for each view of the provided SfMData container.
 * @param[in,out] featuresPerView
 * @param[in] sfmData The provided SfMData container
 * @param[in] folder The feature Folder
 * @param[in] imageDescriberType The imageDescriber type
 * @return true if the features are correctlty loaded
 */
bool loadFeaturesPerView(feature::FeaturesPerView& featuresPerView,
                         const SfMData& sfmData,
                         const std::string& folder,
                         const std::vector<feature::EImageDescriberType>& imageDescriberTypes);

} // namespace sfm
} // namespace aliceVision
