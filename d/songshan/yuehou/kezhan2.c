// Room: /d/yuehou/kezhan2.c

#include <room.h>
inherit ROOM;

protected int have_person(object room)
{
        if(!room)
                return 0;
        return sizeof(filter_array(all_inventory(room),(: userp($1) && !wizardp($1) :)));
}

void create()
{
        set("short", "��ջ��¥");
        set("long", @LONG
�������ڿ͵��¥�������ϣ����������ӿͷ��ﲻʱ�غ���
�Ĵ�����һ��߹�һ�󡣲�ʱ��˯�����ʵ��ÿͽ�����������
¥�µ��ƹ񴦸���Ǯ������˯����
LONG
        );

        set("exits", ([
                "down" : __DIR__"kezhan",
                "east" : __DIR__"kezhan3",
                "north" : __DIR__"kezhan4",
                "west" : __DIR__"kezhan5",
                "south" : __DIR__"kezhan5",
        ]));

        setup();
//        create_door("east", "����", "west", DOOR_CLOSED);
//        create_door("north", "����", "south", DOOR_CLOSED);
 //       create_door("west", "����", "east", DOOR_CLOSED);
 //       create_door("south", "����", "north", DOOR_CLOSED);
}

int valid_leave(object me,string arg)
{
        object room;

        switch (arg)
        {
                case "east":
                case "west":
                case "north":
                case "south":
                        if(query("exits/"+arg))
                                room = find_object(query("exits/"+arg));
                        break;
        }

        if( room && have_person(room) )
                return notify_fail("�Ǽ�ͷ��������ˡ�\n");
        else
                return 1;
}

