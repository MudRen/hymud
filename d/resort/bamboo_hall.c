 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������СС�Ĵ����ݡ����м������еļҾ߶�������
���ɵġ����е����Ϸ���һ���������ɰ��ߡ���ѩɽׯ����
Ů��������Ʒ�����塣
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"front_yard",
  "north" : __DIR__"back_yard",
  "west" : __DIR__"teagarden",
  "east" : __DIR__"restroom",
]));
       set("objects", ([
                __DIR__"npc/master" : 1,
                __DIR__"npc/master2" : 1,
                __DIR__"npc/girl" : 1,
        ]) );
        set("valid_startroom", 1);
        set("coor/x",-1230);
        set("coor/y",60);
        set("coor/z",-10);
        setup();
}
int valid_leave(object me, string dir)
{
        object ob;
    if( me->query("class") != "legend" && (dir == "east"|| dir== "west")) {
        if(ob=present("master tieshao", this_object())){
                return notify_fail("����΢΢������ü��\n\n��������·��"+ob->name()+"��ס�� ��\n");
                } else if(ob=present("master xuerui", this_object())){
                        return notify_fail(ob->name()+"��ü΢����\n\n��������·��"+ob->name()+"��ס�� ��\n");
                }
        }
        return 1;
}  
