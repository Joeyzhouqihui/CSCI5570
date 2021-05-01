#!/bin/bash
echo "PageRank"
echo "org:"
./ligra/apps/PageRank inputs/unweighted/pokec_csr
echo "hubsort:"
./ligra/apps/PageRank inputs/unweighted/pokec_csr_hubsort
echo "hubcluster:"
./ligra/apps/PageRank inputs/unweighted/pokec_csr_hubcluster
echo "gorder:"
./ligra/apps/PageRank inputs/unweighted/pokec_csr_gorder

echo "PageRankDelta"
echo "org:"
./ligra/apps/PageRankDelta inputs/unweighted/pokec_csr
echo "hubsort:"
./ligra/apps/PageRankDelta inputs/unweighted/pokec_csr_hubsort
echo "hubcluster:"
./ligra/apps/PageRankDelta inputs/unweighted/pokec_csr_hubcluster
echo "gorder:"
./ligra/apps/PageRankDelta inputs/unweighted/pokec_csr_gorder

echo "Radii"
echo "org:"
./ligra/apps/Radii inputs/unweighted/pokec_csr
echo "hubsort:"
./ligra/apps/Radii inputs/unweighted/pokec_csr_hubsort
echo "hubcluster:"
./ligra/apps/Radii inputs/unweighted/pokec_csr_hubcluster
echo "gorder:"
./ligra/apps/Radii inputs/unweighted/pokec_csr_gorder

echo "Component"
echo "org:"
./ligra/apps/Components inputs/unweighted/pokec_csr
echo "hubsort:"
./ligra/apps/Components inputs/unweighted/pokec_csr_hubsort
echo "hubcluster:"
./ligra/apps/Components inputs/unweighted/pokec_csr_hubcluster
echo "gorder:"
./ligra/apps/Components inputs/unweighted/pokec_csr_gorder

echo "BC"
echo "org:"
./ligra/apps/BC inputs/unweighted/pokec_csr
echo "hubsort:"
./ligra/apps/BC inputs/unweighted/pokec_csr_hubsort
echo "hubcluster:"
./ligra/apps/BC inputs/unweighted/pokec_csr_hubcluster
echo "gorder:"
./ligra/apps/BC inputs/unweighted/pokec_csr_gorder

echo "KCore"
echo "org:"
./ligra/apps/KCore inputs/unweighted/pokec_csr
echo "hubsort:"
./ligra/apps/KCore inputs/unweighted/pokec_csr_hubsort
echo "hubcluster:"
./ligra/apps/KCore inputs/unweighted/pokec_csr_hubcluster
echo "gorder:"
./ligra/apps/KCore inputs/unweighted/pokec_csr_gorder

echo "MIS"
echo "org:"
./ligra/apps/MIS inputs/unweighted/pokec_csr
echo "hubsort:"
./ligra/apps/MIS inputs/unweighted/pokec_csr_hubsort
echo "hubcluster:"
./ligra/apps/MIS inputs/unweighted/pokec_csr_hubcluster
echo "gorder:"
./ligra/apps/MIS inputs/unweighted/pokec_csr_gorder

