 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "ŭ��ʯ��");
        set("long", @LONG 
��ʯ���ϸ����죬�¾��̺����������ب��ŭ����������֮�䣬�·����֮����
�˶��ϣ����������з����ǳ�Ҳ����ȥ���溣���š�ŭ�����Σ��·�һ�����˾Ϳ�
����ǧ��ʯ����Ϊ촷ۡ�
LONG 
           ); 
        set("exits",  
           ([  
       "west" : __DIR__"pailangya",
       "east" : __DIR__"nujiao",
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",70); 
        set("coor/y",-1710); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}       
