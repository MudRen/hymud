 inherit ROOM;
#include <room.h>
void create()
{
        set("short", "��������");
        set("long", @LONG
һ�˶�ߣ�ֻ�����˲��е�̴��ľ���ȣ����е����������һЩ�滨��ݡ���
�����������ȵ�һͷð������̴ľ�ذ�����ʪ�ֻ����㼸��Ҫ�������˲Ų��Ử
����
LONG
        );
        set("exits", ([
                "east" : __DIR__"jlonglang2",
                "west" : __DIR__"jlongpool",
        ]));
        set("objects", ([
                __DIR__"npc/smilegirl": 1,
        ]) );
        set("coor/x",-30);
        set("coor/y",40);
        set("coor/z",0);
        setup();
        create_door("west", "̴ľ��", "east", DOOR_CLOSED); 
}
int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    int withtowel=0;
    if( dir == "west" && ob=present("chu chu", this_object()))
    {
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
            if ((string)(inv[i]->query("id")) != "white towel"
                        && !inv[i]->query("no_drop"))
                return notify_fail("��������Ц�������ϴ�����ô�࣬��ô��ϴ�裿\n");
            if( (string)(inv[i]->query("id")) == "white towel" &&
                !(int)(inv[i]->query("equipped")))
                return notify_fail("��������Ц��������Χ��ë���ٽ�ȥ�ɣ���Ҫ�ŵ����ˣ�\n");
            if( (string)(inv[i]->query("id")) == "white towel" )
                withtowel = 1;
        }
        if( !withtowel)
            return notify_fail("��������Ц����û�а�ë����ôϴ��\n");
    }
    if( dir == "east" && ob=present("chu chu", this_object()))
    {
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
            if( (string)(inv[i]->query("id")) == "white towel")
            {
                tell_object(me,ob->name()+"Ц����Ľ�������ʪ��"+
                            inv[i]->name()+"���˻�ȥ��\n\n\n"); 
                destruct(inv[i]);
            }
        }  
    }
    return 1;
}   
