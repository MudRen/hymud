// Room: /d/snow/schoolhall.c
inherit ROOM;
void create()
{
        set("short", "������ݴ���");
        set("long", @LONG
�����Ǵ�����ݵ�����������̫ʦ��һ���ſ�������ſڣ���
���������λ��ʦ����������������λ����һ����ݲ�ͬ���ǣ�
ǽ�Ͼ�Ȼ�������������Ϊ���׵��黭����ʾ��������˲��Ǵ���
��ʶ�Ĵֺ�����������˫ȫ�ĸ��ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
//  "south" : "/d/wizard/bigroom",
  "west" : __DIR__"school2",
  "east" : __DIR__"inneryard",
]));
       set("no_sleep_room",1);
       set("no_beg",1);
//        set("objects", ([ /* sizeof() == 1 */
//  "/daemon/class/swordsman/master" : 1,
//  "/d/snow/npc/masterli" :1,
// "/d/snow/npc/masterliu" :1,
// ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
/*
void init()
{
        object me,obj;
        obj=present("master",this_object());
        if (objectp(obj))
        {
                obj->prevent_in(this_player());
        }
}
*/
