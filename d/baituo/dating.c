//ROM dating

inherit ROOM;

void create()
{
        set("short", "����");
        set("long",
             "���ǡ�����ɽׯ���Ĵ������ڲ����輫������������һ�ź�ɫ̴ľ\n"
         "����������·��ž����Ļ�ƿ��һЩ���Ĵ������ıڹ������ҵ��ֻ���\n"
        );
	set("valid_startroom",1);

        set("exits", ([
                "north" : __DIR__"liangong",
                "southdown" : __DIR__"yuanzi",
//                "east" : "quest/menpai/btshan/zhubanzi",
        ]));
 set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("objects",([
		CLASS_D("btshan") + "/ouyangfeng" : 1,
                __DIR__"npc/yahuan" : 2,
                "/d/biwu/champion_bt":1,
                "quest/menpai/btshan/shi":1,
        ]));
//        set("no_clean_up", 0);
        setup();

        "/clone/board/baituo_b"->foo();

        replace_program(ROOM);
}

