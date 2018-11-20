% ---------------------------------------------------------------------
\title{Brain Connectivity Visualization - STAR}

% for anonymous conference submission please enter your SUBMISSION ID
% instead of the author's name (and leave the affiliation blank) !!
\author[M. Konefal \& M. Wiedhalm]
       {M. Konefał$^{1}$
        and M. Wiedhalm$^{1}$
        \\
         $^1$Group 15\\
       }

% ------------------------------------------------------------------------

% if the Editors-in-Chief have given you the data, you may uncomment
% the following five lines and insert it here
%
% \volume{27}   % the volume in which the issue will be published;
% \issue{1}     % the issue number of the publication
% \pStartPage{1}      % set starting page
% ------------------------------------------------------------------------


\begin{document}

\maketitle

%-------------------------------------------------------------------------
\section{Introduction}
The brain is the most complex organ in the human body. It consists of approximately $10^{11}$ neurons and $10^{15}$ connections between them, which form a big network \cite{Murre-Sturdy95}.
This high complexity is one of the reasons why the inner workings are still poorly understood compared to other parts of the human body.
To gain new insights it is important to understand the structure and thus the many connections inside. This is where a lot of projects have emerged in recent times that provide massive amounts of raw data on the human brain, notably among others the Human Connectome Project.

We differentiate three different type of brain connectivity:
\begin{itemize}
	\item \textbf{Structural connectivity} - referring to the network of anatomical links
	\item \textbf{Functional connectivity} - referring to the network formed by the correlation of time-dependent brain activity between different regions of the brain
	\item \textbf{Effective/Connectional connectivity} - referring to the influence that different brain regions exert on each other
\end{itemize}

Acquisition techniques we could divide according to which types of brain connectivity they could discover. We distinguish acquisition techniques for structural connectivity and visualization techniques for connectivity matrices (functional and effective connectivity information could can be represented as a matrix). The techniques for the groups are following:
\begin{itemize}
	\item \textbf{structural} - Diffusion MRI;
	\item \textbf{connectivity matrices} - EEG, MEG, fMRI, Diffusion MRIs
\end{itemize}

The connectivity map first has to be extracted or aproximated from the raw data to get a connectivity matrix / graph. When this comprises the total connections of the brain this is called connectome.
Unfortunately these graphs have a very high dimensionality and thus visualization is a challange. In the following we provide a quick overview of the current techniques that are available to visualize brain connectivity.
\\

%-------------------------------------------------------------------------
\subsection{Acquisition of connectivity data}

Inside an MRI a strong magnetic field is applied over the examined structure\cite{PREIM2014541}. Basically, using this technique we measure the time which is needed for tissues to go back to an equilibrium state after application of an impulse of the magnetic field. To achieve that we send a sequence of impulses which creates a MRI signal (or acquisition mode), one type of them is Echo-Planar Imaging (EPI). Especially interesting are MRI-derived techniques like Diffusion MRI (dMRI) and Functional MRI (fMRI).
\\
In the dMRI we measure indirectly movement of the water in neurons, keeping in mind that water molecules move more often along the constraining structures (\textit{anisotropic diffusion}), from this the shape of the structures can be concluded.
\\
Most significant difference between dMRI and fMRI is that in fMRI instead of the water we measure a signal BOLD which indicate the use of glucose, which is required by active neurons. This information can help us identify to what extend particular parts of the brain are activated. For fMRI we can define two subcategories: when a test subject is asked to do simple task (e.g. tapping with a finger) during the fMRI examination then we call it task state fMRI (tfMRI) and when the subject is in a relaxed mental state during examination - resting state fMRI (rfMRI).
\\
Electroencephalography (EEG) and magnetoencephalography (MEG) are based on measuring difference in voltage and localized magnetic field respectively. However, these techniques have a limited spatial resolution compared to MRI-based techniques.

%-------------------------------------------------------------------------
\section{Human Connectome Project}

As a one of a result of the revolution in the non-invasive neuroimaging methods we are able to analyze and visualize the human brains structure, its function and connectivity in unprecedented detail\cite{Essen:2013}. In 2010, NIH Neuroscience Blueprint Institutes and Centers awarded the Human Connectome Project (HCP) grants to two consortia, one led by Washington University, the University of Minnesota, and Oxford University, and the other led by MGH and UCLA. The aim of that ongoing project is to characterize human brain connectivity and function in a population of 1200 healthy adults. Acquired data should also enable comparison between brain circuit, behaviour, and genetics at the level of individual subjects.
\\
To achieve that goal, a particular set of data was collected:
\begin{itemize}
	\item For all 1200 subjects:
	\begin{itemize}
		\item structural MRI
		\item resting-state fMRI (rfMRI)
		\item task fMRI (tfMRI)
		\item diffusion MRI (dMRI)
	\end{itemize}
	It was done on a customized 3T scanner at Washington University, additionally 200 subject were also scanned an a 7 T scanner at the University of Minnesota.
	\item A subset of 100 subject was studied using MEG/EEG (resting-state and task-evoked) carried out at St. Louis University.
	\item Standardized behavioural tests were done, to increase the prospects that finding based on the HCP data can in the feature be related to other large-scaled project comparing brain and behaviour.
	\item Also blood samples were acquired at the time of each subject's visit. Genotyping will be carried out\cite{releaseNotes}.
\end{itemize}
The project phase of acquiring data for visualization is already completed\cite{releaseNotes}.
Data is freely available to the scientific community in raw form, but also after multiple levels of processing needed to analyse and interpret the data. To archieve the aim of creating a database which could be used by the vast community of researchers around the world the first phase of the project considered i. a. creation of: 3T scanning protocol and 7T scanning protocol (to acquire raw data), minimal processing pipelines, analysis approaches, informatics (one platforms for handling the data \textit{ConnectomeDB} and a second for visualization and analysis \textit{Connectome Workbench}). Examples of images provided by this project we ca be seen in figure \ref{fig:connectome} and \ref{fig:connectome_rs}.

\begin{figure}[htb]
  \centering
  % the following command controls the width of the embedded PS file
  % (relative to the width of the current column)
  \includegraphics[width=.8\linewidth]{connectome}
  % replacing the above command with the one below will explicitly set
  % the bounding box of the PS figure to the rectangle (xl,yl),(xh,yh).
  % It will also prevent LaTeX from reading the PS file to determine
  % the bounding box (i.e., it will speed up the compilation process)
  % \includegraphics[width=.95\linewidth, bb=39 696 126 756]{sampleFig}
  %
  %
    \caption{\label{fig:connectome}
	White matter fiber architecture from the Connectome Scanner dataset. The fibers are color-coded by direction: red = left-right, green = anterior-posterior, blue = ascending-descending (RGB=XYZ)\cite{eHCP}.    
    }
\end{figure}

\begin{figure}[htb]
  \centering
  % the following command controls the width of the embedded PS file
  % (relative to the width of the current column)
  \includegraphics[width=.8\linewidth]{FunctionalConnectivity_rfMRI}
  % replacing the above command with the one below will explicitly set
  % the bounding box of the PS figure to the rectangle (xl,yl),(xh,yh).
  % It will also prevent LaTeX from reading the PS file to determine
  % the bounding box (i.e., it will speed up the compilation process)
  % \includegraphics[width=.95\linewidth, bb=39 696 126 756]{sampleFig}
  %
    \caption{\label{fig:connectome_rs}
           A map of the average \textit{functional connectivity} in the human cerebral cortex collected on healthy subjects while at rest in the MRI scanner. Regions in yellow/red are functionally connected to the \textit{seed} location in the right frontal cortex (center of yellow area in upper right), whereas regions in green and blue are weakly connected or not connected at all.)\cite{rseHCP}.
    }
\end{figure}
%-------------------------------------------------------------------------

\subsection{Data Processing}
In order to make the best use of the high-resolution HCP datasets, it is critical to compensate as much as possible for distortions, biases, and artifacts and also to acknowledge the potential impact of residual confounds\cite{Essen:2013}. During the first two years of the HCP, intensive efforts were put into optimizing a set of preprocessing steps. Results provide improvement for all MRI modalities. For fMRI, one set of issues revolves around de-noising, and removal of motion confounds. Another involves brain parcellation and network analysis. For dMRI, key issues involve fiber orientation estimation followed by probabilistic tractography. In the next section we look closer to these which were applied to dMRI. Three mayor software packages used by the HCP pipelines are FSLNets, FreeSurfer, and Connectome Workbench. 

%-------------------------------------------------------------------------
\subsection{Improvements for dMRI}
For structural connectivity analysis, in particular, diffusion MRI (dMRI) tractography algorithms was used for structural connectivity analysis, it can successfully localize fibre bundles within white matter and therefore allows the study of specific brain pathways\cite{Sotiropoulos:2013}. This approach have some limitation and we will try to give short overview how researches in the HCP overcomed this limitations.
%-------------------------------------------------------------------------

\subsubsection{Image Reconstruction}

Images are obtained from reconstruction combining information from different receivers. It could strongly affected fibre orientation estimation and subsequently bias tractography results, because of Rician properties and noise. This effects increase with the number of receiver channels. To reduce effect of the noise (especially noise floor) the number of channels (in this case 32) was minimized using a sensitivity encoding (SENSE). This encoding combines data from all channels into a single complex image, whose magnitude is subsequently computed. It therefore preserves the Rician properties and increases the dynamic range of the signal.

\subsubsection{Distortion Correction}
Even small inhomogeneities of the magnetic field create distortions in EPI images (created from EPI signals). Inhomogeneities could be caused by different factors, like by object itself, other reason could be rapid switching of the diffusion gradients (gradients in MRI are used to localize position in space volume of the subject which is currently analysed by scanner).
\\
It was developed a model-based approach that simultaneously considers and corrects all types of distortions. The distortion correction is based on the idea of manipulating the acquisitions so that a given field inhomogeneity manifests itself differently in different images. Then it could be used for creating generative model to make predictions about how dMRI volumes should look like for every point in space and for different distortions. Inversion of this model enables accurate estimation of the corrected data. Combining pairs of images, a susceptibility induced off-resonance field can be estimated. For distortions caused by rapid switching gradient, it is analysed complementary information in dMRI scans with opposing diffusion gradient. These and other predictions could be combined and create a model of distorted data. We could correct measurements comparing it to mentioned model in an iterative, active process.

%-------------------------------------------------------------------------

\subsubsection{Fibre Orientation Estimation}
Several methods have been proposed for inferring the fibre orientation density function (fODF) from diffusion MRI, targeting either the fODF directly or approximations of it. The underlying idea for the former group of methods is that the measured signal \textbf{S} can be considered as the spherical convolution of the fODF \textbf{F} and an impulse response function \textbf{R}. Then to estimate \textbf{F} we deal with deconvolution function.
\\\
The ball \& stick model is a powerful parametric deconvolution method, but it is not appropriate for multi-shell datasets. Consequently, it was developed as a parametric deconvolution extension of the ball \& stick model, which do not have this disadvantage. The single-fibre kernel \textbf{R} was modified to represent the signal arising from a distribution of diffusivities within a voxel, rather than a single diffusivity. Using a Gamma distribution of diffusivities allows an analytic parametric expression to be obtained. It is also a phenomenological model that can capture effects from multiple diffusion compartments and/or partial volume in a more flexible way than the simpler stick kernel. Thanks to this model crossing-fibre sensitivity was increased.

\subsubsection{Tractography}
Tactography is a general term for methods of visualizing circuits that connect different parts of the brain structurally.
Starting point is data that is gathered using diffusion weighted MRI, though this is not without problems.
Significant inacuracies have been found in some cases when the dwi tactography was compared to a ground thruth \cite{maier2017challenge}.
From there directional glyphs can be generated and further be converted to a series of tracts or channels.
To visualize the channels many very fine lines or tubes have to be displayed which poses a challange for
vertex based redering \cite{margulies2013visualizing}. Though through the abstraction of these channels to gpu accelerated tuboids (which are more like fine lines) the process could be significantly improved \cite{petrovic2007visualizing}
The result is a representation of the structural nerve fibers inside the brain \ref{fig:connectome}. The possibility is there to color code the individual fibers depending on their direction, lighting and shadows can also be used to improve perception \ref{fig:connectome_prob}.

\begin{figure}[htb]
  \centering
  % the following command controls the width of the embedded PS file
  % (relative to the width of the current column)
  \includegraphics[width=.8\linewidth]{connectome_prob}
  % replacing the above command with the one below will explicitly set
  % the bounding box of the PS figure to the rectangle (xl,yl),(xh,yh).
  % It will also prevent LaTeX from reading the PS file to determine
  % the bounding box (i.e., it will speed up the compilation process)
  % \includegraphics[width=.95\linewidth, bb=39 696 126 756]{sampleFig}
  %
    \caption{\label{fig:connectome_prob}
           Fibers are enhanced with shadows and lighting \cite{peeters2006visualization}.
    }
\end{figure}
%-------------------------------------------------------------------------
\subsubsection{Graph representation}
For the visualization of functional and connectional data a different aproach is used where we take a more abstract route.
There are also methods which involve the structural representation of the brain with the added connections, though this has the disadvantage that with an increasing number of connections the readability increases compared to a pure abstract graph.
In \ref{fig:connectivity} the individual functional brain regions are fitted on a circle with a connection graph in the middle, additionally the regions are also color coded onto the physical brain structure for a better location understanding.

\begin{figure}[htb]
  \centering
  % the following command controls the width of the embedded PS file
  % (relative to the width of the current column)
  \includegraphics[width=.8\linewidth]{connectivity}
  % replacing the above command with the one below will explicitly set
  % the bounding box of the PS figure to the rectangle (xl,yl),(xh,yh).
  % It will also prevent LaTeX from reading the PS file to determine
  % the bounding box (i.e., it will speed up the compilation process)
  % \includegraphics[width=.95\linewidth, bb=39 696 126 756]{sampleFig}
  %
    \caption{\label{fig:connectivity}
           Functional connectivity of the brain \cite{brainart}.
    }
\end{figure}

\section{Responsibilities}

M. Konefał worked on:
\begin{itemize}
\item Introduction
\item Human Connectome Project
\item Processing of the raw data
\end{itemize}

M. Wiedhalm worked on:
\begin{itemize}
\item Introduction
\item Tractography
\item Graph representation
\item General additions
\end{itemize}

%-------------------------------------------------------------------------
\bibliography{egbibsample}
\bibliographystyle{eg-alpha}
%\bibliographystyle{eg-alpha-doi}

\end{document}
