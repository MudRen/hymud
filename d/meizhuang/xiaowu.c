// xiaowu.c
inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
��������С���Ժ󣬷������ﾹȻ��������Ĳ��ܴ�����
��Ȼ����˵�ǽ�̻Իͣ��������������Ƶ����������������Σ�����
�磬��������......����ʤ����ǽ�Ϲ���һ����������һ�߰���
���١�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "out" : __DIR__"xiaoyuan",
        ]));
        set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("objects", ([ /* sizeof() == 2 */
            __DIR__"npc/huangzhong-gong" : 1,
            __DIR__"obj/wall" : 0,
                "/quest/menpai/newmp/shi8" : 1,
                "/d/biwu/champion_mz" : 1,
                "/d/meizhuang/npc/mdizi" : 2,
                "/d/meizhuang/npc/jiading2" : 2,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "meizhuang");

        setup();
        replace_program(ROOM);
}

