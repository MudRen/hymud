// inn.c
// edit by pian
#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "�����ջ");
        set("long", @LONG
������һ��С��ջ���Ͼɵ�������Ϊ�����ʹ�ö�����ں���
�������߸���һ��������������һ�������������������ǿ�ջ��
�����������ߵ�ǽ�ڱ�����һ��ͨ����¥������¥�ݣ�¥���¾���
��̨�������ǿ�ջ�ĳ��ڣ��ſ�һ��ֽ���������ҡ�ڣ�����д��
�������ջ������˼�Ǽ�ʹ��û��Ǯ��Ҳ��ӭ�������������飬��
�����硣������һ��ľ��ͨ������ĳ����������ſڵĵط���һ��
��ľ��ɵ�����(sign)��
LONG
        );
   set("item_desc", ([ /* sizeof() == 7 */

	"�Ƹ�": "����ϸ�������ƾƸ������ĺ�ֽ�������ˣ����ӵ����ĸ�������\n"
                "�������ӾƷ������ӡ�ġ�����ơ������ļ����һƷ�����ˣ���\n"
                "�кü�̳�����������¥�ĳ����Ͼơ�\n",
        "��̨": "��̨���������һ̳̳������ֽ���ľƸף���Щ�ǿ�ջ�ƹ�������\n"
                "���ĳ����Ͼƣ����������Ȥ�����������ƹ��й���Щ�����Ͼ���\n"
                "�ǲ�����\n",
        "����": "һ��ֽ���Ĵ�����߸ߵع�����ǰ������ϣ�����������ֱ�д��\n"
                "�������ջ���ĸ����֣�������ĵ�������һ����«��\n",
        "¥��": "���¥��ͨ����¥���������ͷ���\n",
        "����": "�������������������Ÿ�������¯����ǵ���ס�ӳ���Ʈ������\n"
                "������\n",
        "����": "��Щ��������ɢɢ�ط����ڿ�ջ�����У������൱�Ͼ��ˡ�\n",
        "sign":"����д���������ջ��\n",
        ]));
        // This enables players to save this room as their startroom.
       	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
       set("exits", ([
                "east"          : __DIR__"guangchang_w",
                "west"          : __DIR__"inn_kitchen",
                //"north"          : "/u/y/yuyan/inn",
                //"up"            : "/u/f/free/food",
                //"northwest"     : "/d/wiz/entrance", 
                ]) );
        set("indoors","xueting");
        set("item_desc", ([
                "door": (: look_door, "northwest" :),
        ]) );
       set("objects", ([
  //     __DIR__"npc/traveller" : 3,
           //   "/d/npc/sungoku" : 1,
                __DIR__"npc/paotang" : 1 ]) );
   //     create_door("northwest", "ľ��", "southeast", DOOR_CLOSED);
        setup();
        // To "load" the board, don't ever "clone" a bulletin board.
//        call_other( "/obj/board/common_b", "???" );
}
