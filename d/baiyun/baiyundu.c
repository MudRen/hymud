 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "���ƶ�");
        set("long", @LONG 
�������ģ�����һ�ߡ�������ǰ��Ƶ��ˣ�����������ã�����ɳ̲�����ϸ��
��ˮտ����̣����δ������������İ�ĭ�����ź���������������ƣ��������۴��̡�
һ�������ɾ�һ�㡣����ȥ���Ű����Ǹ��������ͷ��ͣ�����������Ƶ��Ĵ�ֻ������
�ĺ���������䡣
LONG 
           ); 
        set("exits",  
           ([  
       "south" : __DIR__"huangsha1",
       "east" : __DIR__"matou",
            ])); 
        set("objects", ([
//        __DIR__"obj/boat" :1,
        ]));
        set("outdoors", "baiyun"); 
        set("coor/x",15); 
        set("coor/y",-1500); 
        set("coor/z",0); 
        set("valid_startroom", 1); 
        setup(); 
        replace_program(ROOM); 
}      
