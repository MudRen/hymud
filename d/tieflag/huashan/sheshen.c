 inherit ROOM;
void create()
{
        set("short", "�����¶�����");
        set("long", @LONG
��˵��ʱ�и�Т�ӣ�Ϊ��Ը��������Ϊ�丸ĸ�β����ڴ˴��������¡�̽ͷ��
����ȥ���±�ֱ�������а��ɣ��µ׹��ֽ���Ϫ���̻�������Ŀѣ���������ɵ�
�������������о��������������ǲ�����������ȥ�ġ�
LONG
        );
    set("exits", ([ 
        "northeast" : __DIR__"lianhua",
        ]));
   
    set("outdoors", "huashanfy"); 
    set("coor/x",-650);
    set("coor/y",-103);
    set("coor/z",80);
    set("objects", ([
                __DIR__"npc/kuan" : 1,
        ]));  
    
        setup();
    replace_program(ROOM);
}    
