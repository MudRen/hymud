 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "��ƫԺ");
        set("long", @LONG
Ժ��������÷�����硣ÿ�ö�����׳�ɳ�����Ȼ���˾����չˡ�÷��
֮�仹���˹����ѵ�С�ӹ�����������ˮ�������ʣ������ÿһ�����硣
�����ڶ����ɣ���Ȼ�Ǳ���Ӫ���ķ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yard",
]));
        set("outdoors", "wanmei");
        set("item_desc", ([
                "÷��": "
���ƺ����Կ�������𣩼���������
                        \n", 
        ]) );
        set("coor/x",170);
        set("coor/y",-390);
        set("coor/z",30);
        setup();
}
void init()
{
        add_action("do_chop","chop");
}
do_chop()
{
object vege;
if((int) query("pulled") <= 10)
{
write("�㿳��һ��÷��������ڻ��\n");
vege = new(__DIR__"obj/tree");
vege->move(this_player());
add("pulled",1);
return 1;
}
else
        write("�����˿����ˣ���\n");
        return 1;
} 
void reset()
{
:: reset();
delete("pulled");
} 
