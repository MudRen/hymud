 inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
void create()
{
        set("short", "ɽׯǰԺ");
        set("long", @LONG
ʮ�ɷ�԰��Ժ���������ż��Ŵ��̵��߲ˡ�Ժ����һ��С����
������һľͰ��Ͱ��ϵ����������Ȼ��������ˮ�ġ�Ժ����һ��
���ŵļ����տ�������ľ������̫��������ɹ�ɡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"gate",
  "east" : __DIR__"meidang",
  "north" : __DIR__"woodroom",
  "south" : __DIR__"woodhouse",
  "northeast" : __DIR__"left",
  "southeast" : __DIR__"right",
]));
        set("outdoors", "wanmei");
        set("resource/water",1);
        set("liquid/container","С��");
        set("item_desc", ([
                "�߲�": "
                        ������̵��߲�ѽ���������������Σ������죩һ�ðɣ�\n",
                "ľ��": "
                        ����˵�ľ�ģ��ã�����룩��������\n",
                //"С��": "
                //        С���ܻ�����������������������⣩��ȥ��\n"  
        ]) );
        set("coor/x",150);
        set("coor/y",-400);
        set("coor/z",30);
        setup();
}
void init()
{
    add_action("do_pull", "pull");
    add_action("do_pick", "pick");
    add_action("do_climb", "climb");
} 
void reset()
{
    ::reset();
    delete("pulled");
    delete("picked");
} 
int do_climb()
{
    write("��̫���ˣ�����\n");
    return 1;
} 
do_pull()
{
    object vege;
    if((int) query("pulled") <= 10)
    {
        vege = new(__DIR__"obj/vege");
        message_vision("$N����һ��"+vege->query("name")+"���ڻ��\n", this_player());
        vege->move(this_player());
        add("pulled",1);
        return 1;
    }
    else
        write("�����˰ι��ˣ���\n");
    return 1;
} 
int do_pick()
{
    object vege;
    if((int) query("picked") <= 10)
    {
        vege = new(__DIR__"obj/wood");
        message_vision("$N����һ��"+vege->query("name")+"���ڻ��\n", this_player()); 
        vege->move(this_player());
        add("picked",1);
        return 1;
    }
    else
        write("�������ù��ˣ���\n");
    return 1;
}   
