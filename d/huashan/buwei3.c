// buwei3.c

inherit ROOM;

void create()
{
        set("short", "ƫ��");
	set("long", @LONG
ƫ���﹩���Ż�ɽ������ʦ����λ�������񰸵�ǽ���ǻ�ɽ�ɿ�ɽ��
ʦ����ʦ�Ļ��󡣻��������������ǳ�����������¯������������㣬
��������������ɢ����һ��̴��ζ������������ͨ�������������
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"buwei1",
	]));
	set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
         set("objects", ([
           "quest/menpai/huashan/shi" : 1,
                "/d/huashan/npc/nvdizi" :2,
                "/d/huashan/npc/nandizi" :2,
                "/d/biwu/champion_hs" :1,
        ]));set("no_clean_up", 0);
        set("valid_startroom","1");

        setup();
        "/clone/board/huashan_b"->foo();
        replace_program(ROOM);
}
