
// void.c (re-created after Elon screwed it up on 07-24-95)

inherit ROOM;

void create()
{
	set("short","������԰");
	set("long",@LONG	
������Ǵ�˵�е� VOID -- �������ʦ��������԰. �㿴������һƬ
��ãã��, ��һ���������ð��һֻ���, �ݸ���һ�ޡ��ɿڿ��֡�(tm), 
Ȼ��վ��һ�Ժ�а���Ц��. �ֹ���һ��, һֻ���������˹���, һ���ı�
����ֻ��첢��������������ƿ����, ��Ц������ʹ�����ǰ��ʧ��.
��ҡҡͷ, ���ֵط����ǲ�Ҫ��̫�õĺ�.
LONG
	);
     set("exits", ([
      "out"    : "/d/snow/inn",
      ]) );
// i add a exit, because when some place wrong,players maybe be here,
// they can't leave here, only wiz can help them.
//if wiz is not in mud, maybe they will cry all day and all night.
// By apollo 
	setup();
	replace_program(ROOM);
}

