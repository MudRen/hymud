// Room: /city/yaopu.c
// YZC 1995/12/04 
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С
������ɢ�������ġ���ҽƽһָ���ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�
һ��С���վ�ڹ�̨���к��Ź˿͡���̨������һ�ŷ��ƵĹ��(guanggao)��
LONG );
	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
��ҩ��\t��ʮ������
�޳������һ�����ҩʦ���䣬������ǣ�
�쾦�����ΰٶ�����Ч������
������ҩ���ϰ����顣\n",
	]));
//	set("item_desc", ([
//		"guanggao" : "�����ϰ�ƽһָ�����ҩδ�飬������ͣӪҵ��\n",
//	]));

set("roomif","$botten#�鿴|����|����|ĥҩ|����|ҩ��:list|buy <��Ʒѡȡ>|ask ping about job|moyao|ask huoji about job|give 1 silver to huoji$#");
	set("objects", ([
	       __DIR__"npc/ping" : 1,
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"dongdajie2",
		"north" : "/quest/liandan/liandan1",
	]));
//          set("no_fight", 1);
         set("no_steal", 1);
//      set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}
void init()
{
	add_action("do_moyao","moyao");
}
int do_moyao(string arg)
{
	int exp,pot;
       object me=this_player();
         if (me->is_busy() )
       return notify_fail("�㻹�������ĥ���ҩ�ɣ�\n");
        if (me->query("job_moyao")<1)
       return notify_fail("û�����ϰ�ͬ����ɲ���ĥҩӴ���\n");
       me->set("job_moyao",0);
       message_vision(HIY
      "$N���˲����ϵĺ�ˮ������һ������ҩ����ʼĥҩ�ˣ���\n"NOR,me);
       message_vision(HIR
      "$N��Ȼ����ҩ������һЩ���������û��ע��͵͵�ؽ��˻��ˣ���\n"NOR,me);
       MONEY_D->pay_player(this_player(), 50);
       exp=random(30)+1;
       
       
       if (me->query("combat_exp",1)>180000) exp=2;
       pot=exp*3/4;
       me->add("potential", pot);
       me->add("combat_exp", exp);
       tell_object(me,"��õ���"+exp+"�ľ��顣"+pot+"��Ǳ�ܡ�\n");
       me->add_temp("nbjob26",1);
       me->add("jing",-60);
       me->start_busy(8);
       return 1;
}
