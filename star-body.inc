% ---------------------------------------------------------------------
\title{Brain Visualization - STAR Report}

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

\begin{abstract}

Human Connectom Project is one of the most ambitious projects in the history of neuroscience and it is comming to an end. Its aim is to provide knowledge which shed the light on the anatomical and fuctional connectivity of the healthy human brain. It was done by acquiring, processing and distribuating for unseen before scale of medical data, which right now is avaliable to te scientific community. It give unprecednet oportunity to researchers from different fields to explore this incredible human organ. In this article we give short project overview, focusing more on improvments which have been done in preprocessing dfMIR data.

\end{abstract}



%-------------------------------------------------------------------------
\section{Introduction}

Brain is our most important organ\cite{Murre-Sturdy95}. It is complicated nervous system which controls most of activities in our body and play key part in human cognition. This organ could not be replaced and its function could not be artificially taken over, consequently any damage or serious pathology change could put at risk whole organism\cite{PREIM2014541}. In the same time it is one of the least know organs i.a. because of it complicity (network consist approximately $10^{11}$ neurons and $10^{15}$ connections between of them\cite{Murre-Sturdy95}). We dispose of acquisition techniques which help as to explore \textit{in vivo} this wonder of nature, but with such quantity of data it is also important to transform acquired data to the form in which it could be analysed or visualize.
\\
Aquisition techniques we could divide focusing on the visualization of point-to-point brain connectivity to following categories\cite{PREIM2014541}:
\begin{itemize}
\item structural - using Diffusion MRI;
\item connectivity matrices - using EEG, MEG, fMRI, Diffusion MRIs
\end{itemize}
Especially interesting are MRI derived techniques like Diffusion MRI and fMRI. In MRI strong magnetic field is applied over the examined structure. Basically in these technique we measure a time which is needed for tissues to go back to equilibrium state after application of an impulse of the magnetic field. To achieve that we send sequence of impulses which creates MRI signal, one of them is Echo-Planar Imaging (EPI).
\\
In the Diffusion MRI we measure indirectly movement of the water in neurons, keeping in mind that water molecules move more often along the constraining structures (\textit{anisotropic diffusion}), form that fact shape of that structures could be concluded.
\\
Most significant difference comparing mentioned technique to fMRI is that instead of water we measure signal BOLD which indicate use of the glucose, which is required by active neurons. That information could help us tu identify to what extend particular part of the brain are activated. For fMRI we can precise two subcategories: when subject is asked to do simple task (e.g. taping with a finger) simultaneously with fMRI examination \textit{task state fMRI (tfMRI)} and when subject is in a relaxed mental state \textit{resting state fMRI (rfMRI)}.

%-------------------------------------------------------------------------

\section{Human Connectome Project}
As a one of a result of revolution noninvasive neuroimaging method in the last paragraph we are enable the analysis and visualization of human brain structure, function and connectivity in unprecedented detail\cite{Essen:2013}. In 2010, NIH Neuroscience Blueprint Institutes and Centers awarded Human Connectome Project (HCP) grants to two consortia, one led by Washington University, the University of Minnesota, and Oxford University. The aim of that ongoing project is to characterize human brain connectivity and function in a population of 1200 healthy. Acquired data should also enable comparison between brain circuit, behaviour, and genetics at the level of individual subject.
\\
To achieve that aim, particular type of data was collected:
\begin{itemize}
	\item For all 1200 subjects:
	\begin{itemize}
		\item structural MRI
		\item resting-state fMRI (rfMRI)
		\item task fMRI (tfMRI)
		\item diffusion MRI (dMRI)
	\end{itemize}
	It was done on a customized 3T scanner at Washington University, additionally 200 subject was also scanned an a 7 T scanner at the University of Minnesota.
	\item A subset of 100 subject was studied using MEG/EEG (resting-state and task-evoked) carried out at St. Louis University.
	\item Standardized behavioural tests was taken, to increase the prospects that finding based on the HCP data can in the feature be related to other large-scaled project comparing brain and behaviour.
	\item Also blood samples was acquired at the time of each subject's visit. Genotyping will be carried out\cite{releaseNotes}.
\end{itemize}
The project phase of acquiring data for visualization is already completed\cite{releaseNotes}.
Data are freely available to the scientific community in the raw form , but also after the multiple levels of processing needed to analyse and interpret the data. Ta achieve aim of creating a database which could be use by vast community of researchers around the world the first phase of the project considered i. a. 3T scanning protocol and 7T scanning protocol (to acquire raw data), minimal processing pipelines, analysis approaches, informatics (one platforms for handling the data \textit{ConnectomeDB} and second for visualization and analysis \textit{Connectome Workbench}).

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
  \parbox[t]{1.0\columnwidth}{\relax
           White matter fiber architecture from the Connectome Scanner dataset. The fibers are color-coded by direction: red = left-right, green = anterior-posterior, blue = ascending-descending (RGB=XYZ)\cite{eHCP}.
           }
  %
  \caption{\label{fig:connectome}
           One of the pictures from the gallery of Human Connectome Project.}
\end{figure}

\subsection{Aspects of the Preprocessing Pipeline}
In that sections we focus on major improvements which was done in the framework of the project. Main advances was made for data coming from dMRI\cite{Sotiropoulos:2013}.
\\
Tractography algorithms was used for structural connectivity analysis, which can successfully localize fibre bundles within white matter and therefore allows the study of specific brain pathways. This approach have some limitation, we will try to give short overview researches in the HCP overcome this limitations.
%-------------------------------------------------------------------------

\subsubsection{Image Reconstruction}
Images are obtained from reconstruction combining information from different receivers. It could strongly affected fibre orientation estimation and subsequently bias tractography results, because of Rician properties and noise. This effects increase with the number of receiver channels. To reduce effect of the noise (especially noise floor) the number of channels (in this case 32) was minimized using a sensitivity encoding (SENSE). This encoding combines data from all channels into a single complex image, whose magnitude is subsequently computed. It therefore preserves the Rician properties and increases the dynamic range of the signal.

\subsubsection{Distortion Correction}
Even small inhomogeneities of the magnetic field create distortions in EPI images (created from EPI signals). Inhomogeneities could be caused by different factors, like by object itself, other reason could be rapid switching of the diffusion gradients (gradients in MRI are used to localize position in space volum of the subject which is currently analysed by scanner).
\\
It was developed a model-based approach that simultaneously considers and corrects for all types of distortions. The distortion correction is based on the idea of manipulating the acquisitions so that a given field inhomogeneity manifests itself differently in different images. Then it could be used generetive model about what images should for every point in space and diffrent distortions. Inversion of this model enables accurate estimation of the corrected data. Combining pairs of images, a suscebility induced off-resonance field can be estimated. For distortions coused by rapid switching gradient, itis analyse complementary information in dMRI scans with opposing diffusion gradient. These and other predictions could be combined and create a model of distorded data. We could correct measurments comparing it to mentioned model in an iterative, active process.

%-------------------------------------------------------------------------

\subsubsection{Fibre Orientation Estimation}
Several methods have been proposed for inferring the fibre orientation density function (fODF) from diffusion MRI, targeting either the fODF directly or approximations of it. The underlying idea for the former group of methods is that the measured signal \textbf{S} can be considered as the spherical convolution of the fODF \textbf{F} and an impulse response function \textbf{R}. Then to estimate \textbf{F} we deal with deconvolution function.
\\\
The ball \& stick model is powerful parametric deconvolution method, but it is not appropriate for multi-shell datasets. Consequently, it was developed a parametric deconvolution extension of the ball \& stick model, which is do not have this disadventage. The single-fibre kernel \textbf{R} was modified to represent the signal arising from a distribution of diffusivities within a voxel, rather than a single diffusivity. Using a Gamma distribution of diffusivities allows an analytic parametric expression to be obtained. It is also a phenomenological model that can capture effects from multiple diffusion compartments and/or partaial volume in a more flexible way than the simpler stick kernel. Thanks to this model crossing-fibre sensitivity was increased.
\subsubsection{Tractography}
Probabilistic streamline tractography is employed to propagate spatially the local fibre orientation information. Tractography algorithm has been modified to handle surfaces and volumes as regions of interest. Therefore, extra functionality is supported and handling of surface vertices, such as seeding from the grey/white matter boundary surface or using the pial surface as a termination mask.
\\
It was not decided at the fist phase which strategy should be used for represent structural connectivity matices, we do not find which was finally choosen.
%-------------------------------------------------------------------------

\section{Responsibilities}

M. Konefał worked on:
\begin{itemize}
\item Preperation of latex file
\item Section - Introduction
\item Section - Human Connectome Project
\item Section
\end{itemize}

M. Wiedhalm worked on:
\begin{itemize}
\item
\end{itemize}

%-------------------------------------------------------------------------
\bibliography{egbibsample}
\bibliographystyle{eg-alpha}
%\bibliographystyle{eg-alpha-doi}

\end{document}
