 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        object con,item;
        set("short", "ն��̨");
        set("long", @LONG 
������Ÿ�ɮ��ϴ�ʦӦ���Ƴ���֮�����������ˣ�������̨���ɴ󾪣��Ե���
��ʵ�˰��Ƶ��ķ�ˮ�������ڣ�һ���˴��������⣬����Ƴ�Σ�ڵ�Ϧ�����Ƴ�����
˼���գ���ʱ�����ڴ��˽��˸ߴ���ɵ�ն��̨��Ρ�����졣��������δ�̨ʱ����
ɫ������ã���ڲ��ԡ�
LONG 
           ); 
        set("exits",  
           ([  
       "east" : __DIR__"skystreet",
            ])); 
        set("objects",  
           ([  
       __DIR__"obj/shitai" : 1,
       __DIR__"npc/kugua" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("refresh_all_items", 0);
        set("coor/x",5); 
        set("coor/y",-1800); 
        set("coor/z",20); 
        setup(); 
        con = present("shitai",this_object());
//        replace_program(ROOM); 
}
