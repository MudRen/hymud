// Room: /d/jinghai/jhd19.c

inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
�������鷿�Ĳ���֮���Ǿ������ϵģ����ﲻ�����Ӱټҡ�
����ռ�������书�ܼ���ˮ½����ȫ��Ӧ�о��У������ر����
�������ﻹ���ҵ�������ֵ��鼮����˵�����ɵĿ�ɽ��ʦ���
Ϊ�����巸���������ǵ�����ϰ�ԣ���������Ǳ����ɣ��������
�����ڶԸ����ܵ�ս����ս�޲�ʤ��
LONG
	);
  set("valid_startroom", "1");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jhd17",
]));
set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
        set("objects",([
        __DIR__"npc/jiading" : 2,
        __DIR__"npc/jiading2" : 2,
        __DIR__"npc/master1" : 1,
        __DIR__"npc/puren" : 1,
        "/d/biwu/champion_jh" : 1,
        "/quest/menpai/newmp/shi9" : 1,


]));


	setup();
	replace_program(ROOM);
}
