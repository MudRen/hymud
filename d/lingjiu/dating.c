//ROOM dating.c

inherit ROOM;

void create()
{
	set("short", "������");
        set("long",@LONG
����ǡ����չ���������������ȫ���Ծ�ʯ���ɣ�ʯ��֮�侹�ް��
��϶�����˳��档���ڴ������ĸ�ʯ������Ϊ��Ӳ�Ļ���ʯ���ơ�
LONG );
        set("exits", ([
		"north" : __DIR__"changl15",
		"south" : __DIR__"damen",
        ]));
        set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("objects",([
		CLASS_D("lingjiu")+"/xuzhu" : 1,
		"/d/biwu/champion_lj":1,
           "quest/menpai/lingjiu/shi" : 1,
           "/d/lingjiu/npc/dizi" : 3,
	]));
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	setup();
        "/clone/board/lingjiu_b"->foo();
}
