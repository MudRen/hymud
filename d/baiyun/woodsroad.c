 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "����С·"); 
        set("long", @LONG 
���������ϣ���������������б��·���Ե�é�ݽ���ϡ�裬��ľ����������ľ�� 
Խ�ߵ�·Խ������������ȥ��ȻҪ�ߵ������ȥ�ˡ���ç��������ë����Ȼ�Ľ��� 
�ƺ�Ҳ�����������ˡ� 
LONG 
           ); 
        set("exits",  
           ([  
             "northdown" : "/d/manglin/edge4", 
             "south" : __DIR__"plainroad", 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-610); 
        set("coor/z",0); 
        setup(); 
} 
int valid_leave(object who,string dir) 
{ 
        if(userp(who) && random(3)) 
          { 
           who->move(this_object()); 
           return notify_fail("");  
          } 
        return 1; 
}      
