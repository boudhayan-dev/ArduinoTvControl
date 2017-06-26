import numpy as np
import cv2,datetime


cap=cv2.VideoCapture(0)
def cosmetic():
    global draw,cosmetic
    cv2.rectangle(draw,(220,35),(360,95),(150,50,0),5)#right start
    cv2.putText(draw,"START", (240,75), cv2.FONT_HERSHEY_SIMPLEX, 1,(150,50,0), 2)
    cv2.rectangle(draw,(0,35),(150,95),(0,0,255),5)#left start
    cv2.putText(draw,"START", (20,75), cv2.FONT_HERSHEY_SIMPLEX, 1,(0,0,255), 2)

    cv2.rectangle(draw,(0,270),(150,330),(0,0,255),5)
    cv2.putText(draw,"STOP", (20,310), cv2.FONT_HERSHEY_SIMPLEX, 1,(0,0,255), 2)
    cv2.rectangle(draw,(220,270),(360,330),(150,50,0),5)
    cv2.putText(draw,"STOP", (240,310), cv2.FONT_HERSHEY_SIMPLEX, 1,(150,50,0), 2)

    # bottom

    cv2.rectangle(draw,(30,390),(140,450),(0,255,255),5)
    cv2.putText(draw,"START", (40,425), cv2.FONT_HERSHEY_SIMPLEX, 1,(0,255,255), 2)
    cv2.rectangle(draw,(210,390),(310,450),(0,255,255),5)
    cv2.putText(draw,"STOP", (220,425), cv2.FONT_HERSHEY_SIMPLEX, 1,(0,255,255), 2)

    cv2.putText(draw,welcome_text, (20,190), cv2.FONT_HERSHEY_SIMPLEX, 0.5,(0,255,0),1)

rstart=''
rend=''
rstart1=''
rend1=''


lstart=''
lend=''
lstart1=''
lend1=''

bstart=''
bend=''
bstart1=''
bend1=''        

status_text='No operation'
while(True):
    
    ret,fram=cap.read()
    fram=cv2.flip(fram,1)
    #print(fram.shape)
    fram=fram[100:400,400:700]
    frame=cv2.resize(fram,None,fx=1.5,fy=1.5,interpolation=cv2.INTER_CUBIC)
    gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray,(3,3),0)
    ret,thresh = cv2.threshold(blur,75,255,cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)

    #cv2.rectangle(thresh,(0,0),(200,100),(123,150,100),3)
    _, contours, _= cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    c=max(contours,key=cv2.contourArea)
    x,y,w,h = cv2.boundingRect(c)
    cv2.rectangle(thresh,(x,y),(x+w,y+h),(40,255,0),5)
    area = cv2.contourArea(c)
    status=np.zeros(frame.shape,np.uint8)
    
    if (area>1000 and area<=10000):
        draw=np.zeros(frame.shape,np.uint8)
        
        welcome_text='  Move your finger to "STOP" to end.   '
        cosmetic()
        cv2.drawContours(draw,[c],0,(0,255,0),3)
        x,y,w,h = cv2.boundingRect(c)
        if x>290 and y<95 and rend=='' and rstart1=='':
            #print()
            rstart=datetime.datetime.now()
            
            
            
        elif (not rstart=='' and y>270 and x>290 and y<380):
            rend=datetime.datetime.now()
            if ((rend.second)-(rstart.second))>1 and ((rend.second)-(rstart.second))<3:
                status_text='CHANNEL DOWN'
                
                
                
                
            
        if  x>290 and y>270 and y<380 and rend1=='' and rstart=='':
            #print('channel down to up')
            rstart1=datetime.datetime.now()
            
            

        elif (not rstart1==''  and x>290 and y<95 ):
            rend1=datetime.datetime.now()
            if ((rend1.second)-(rstart1.second))>1 and ((rend1.second)-(rstart1.second))<3:
                status_text='CHANNEL UP'
                
               
                

        if x<250 and y<95 and lend=='' and lstart1=='':
            #print()
            lstart=datetime.datetime.now()
            
            
            
        elif (not lstart=='' and y>270 and x<250 and y<380):
            lend=datetime.datetime.now()
            if ((lend.second)-(lstart.second))>1 and ((lend.second)-(lstart.second))<3:
                status_text='VOLUME DOWN'
    





        if  x<250 and y>270 and y<380 and lend1=='' and lstart=='':
            #print('volume down to up')
            lstart1=datetime.datetime.now()
            
            

        elif (not lstart1==''  and x<250 and y<95 ):
            lend1=datetime.datetime.now()
            if ((lend1.second)-(lstart1.second))>1 and ((lend1.second)-(lstart1.second))<3:
                status_text='VOLUME UP'




        if x<100 and y>370 and bend=='' and bstart1=='':
            #print()
            bstart=datetime.datetime.now()
            
            
            
        elif (not bstart==''  and x>220 and y>370):
            bend=datetime.datetime.now()
            if ((bend.second)-(bstart.second))>1 and ((bend.second)-(bstart.second))<3:
                status_text='POWER ON/OFF'
       


        if  x>220 and y>370  and bend1=='' and bstart=='':
            #print('volume down to up')
            bstart1=datetime.datetime.now()
            
            

        elif (not bstart1==''  and x<100 and y>370 ):
            bend1=datetime.datetime.now()
            if ((bend1.second)-(bstart1.second))>1 and ((bend1.second)-(bstart1.second))<3:
                status_text='STOP'
               
        
        print('x'+str(x))
        print('y'+str(y))
        
    else:
        draw=np.zeros(frame.shape,np.uint8)
        welcome_text='Place your finger on "START" to proceed.'
        cosmetic()
        status_text='No operation'
        rstart=''
        rend=''
        rstart1=''
        rend1=''
        lstart=''
        lend=''
        lstart1=''
        lend1=''
        bstart=''
        bend=''
        bstart1=''
        bend1=''
        
    
    cv2.putText(status, status_text,(0,190), cv2.FONT_HERSHEY_SIMPLEX, 1.2,(0,255,0),1)

    
    #print(cv2.contourArea(c))
    cv2.imshow('draw',draw)
    cv2.imshow('raw',frame)
    #cv2.imshow('thresh',thresh)
    cv2.imshow('status',status)
    k=cv2.waitKey(1)
    if k==ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
