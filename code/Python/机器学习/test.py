import pandas as pd
from statsmodels.tsa.holtwinters import ExponentialSmoothing
data = pd.Series()
yhat = ExponentialSmoothing(data, seasonal_periods=4, trend='add', seasonal='add').fit(use_boxcox=True)
