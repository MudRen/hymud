 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "����ɽ"); 
        set("long", @LONG 
��ǽ������ʯɽǡ�ơ����㡱��ɽ���վ���������ͣ���Ϊ�·f��ɽʯ�������� 
��ͬ�Ķ��ݼ��ɣ����е�������ʯ�����г�Ⱥ��ɽ�ͣ��¹Ⱦ��ͣ��������䣬ͬ��Χ
�Ľ��B������ϣ��o���Ի��������ɵ�ӡ�� 
LONG 
           ); 
        set("exits",  
           ([  
       "northwest" : __DIR__"yanchilou",
       "southup" : __DIR__"hillroad",
//           "west"  : __DIR__"beach1", 
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-1710); 
        set("coor/z",11); 
        setup(); 
        replace_program(ROOM); 
}
