// Room: /qingcheng/qiandian.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�ɷ��");
	set("long", @LONG
�������ɷ��ǰ��ɷ�������������������������У�����
�˲ű���֮�ʡ�������������׺�����������ò������ΰ�С��ȴ��
���һ����ʦ���������ҷ����Ĵ����������з�ִ�������á�ɡ������
������(faqi)�������˷����˳�ķ�����Ը��
LONG );
	set("item_desc", ([
		"faqi" : "
�Խ���֮���г�������硱
�������賣����ͨ������
��ɡΪ����Ƽ����ꡱ��
����֮�鶯˳��Ԣ��˳��֮��

",
	]));
	set("roomif","$botten#��������|��������|�������|�Ͻ���Ʒ|��ȡ����|ȡ������:job|quest|ask shi about teamjob|give <��Ʒ> to shi|ask shi about gongxian|give 20 silver to shi$#");
	set("exits", ([
		"southdown" : __DIR__"shangqing",
		"north"     : __DIR__"zhongmen",
	]));
	set("objects", ([
		CLASS_D("qingcheng")+"/yu" : 1,
	"/quest/menpai/newmp/shi4" : 1,
	"/d/qingcheng/npc/dizi" : 4,
	"/d/biwu/champion_qc" : 1,	
	]));
	set("coor/x", -8080);
	set("coor/y", -870);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}