// gangzhang.c ����
#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
	set_name(HIR"��������"NOR, ({ "ryling" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����½̵����ơ������ս�����ٻ�(zhao)�������ָ�(huifu)�Լ������ˡ�\n");
		set("no_put",1);
		set("armor_prop/intelligence",5);
		set("armor_prop/strength",5);
		set("armor_prop/karey",5);
		set("armor_prop/percao",5);
		set("armor_prop/dexerity",5);
		set("armor_prop/constitution",5);set("armor_prop/armor", 200); set("armor_prop/damage",200);
		set("no_get",1);
		set("no_drop",1);
		set("rigidity",100);
		set("material", "steel");
		set("no_put",1);
		set("no_get",1);
		set("no_drop",1);
		set("no_give",1);
		set("no_steal",1);	
	}
	setup();
}
int query_autoload() { return 1; }void init()
{
string info,name,id,file,infoa,infob;
	info = read_file("/data/npc/champion_ry.o");
	if (!info) call_out("destroying", 0); 
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id!=this_player()->query("id")) call_out("destroying", 0); 
}	
	
	add_action("do_zhao","zhao");
	add_action("do_zhao2","huifu");	
}


int do_zhao2(string str)
{
object dizi,me,me2;
int exp;
    int i;
    object obj;
string info,name,id,file,infoa,infob;
	info = read_file("/data/npc/champion_ry.o");
	if (!info) call_out("destroying", 0); 
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id!=this_player()->query("id")) call_out("destroying", 0); 
}
me = this_player();
me2= this_player();


   if (me->query("jing")<100) 
	return notify_fail("�㾫������\n");

        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("����ù��������.\n");
    
    if( !str || str == "")
        obj = me;
    else if ( !obj = present(str,environment(me)))
        return notify_fail("�������: �Ҳ���"+str+"\n");

me=obj;

if( !userp(me) && !wizardp(me2)) 
	return notify_fail("ֻ�ܶ����ʹ��������\n");
if( (string)me->query("family/family_name") != (string)me2->query("family/family_name") ) 
	return notify_fail("ֻ�ܶԱ�����Աʹ��������\n");

if ( me2->is_busy() )
        return notify_fail("������æ�ò����ˣ�\n");
        
if ( me->is_busy() )
        return notify_fail("������æ�ò����ˣ�\n");

	me->set("jing",me->query("max_jing"));me->set("eff_jing",me->query("max_jing"));
	me->set("qi",me->query("max_qi"));
	me->set("eff_qi",me->query("max_qi"));
	me->set("neili",me->query("max_neili"));

	me2->apply_condition("zdizi_busy",3);
	message_vision(GRN "\n$N����Ѫ�;�����˳��õ��˻ָ���\n" NOR, me);	

	return 1;
}
void destroying(){destruct(this_object());   }int do_zhao()
{
object dizi,me;
int exp;
string info,name,id,file,infoa,infob;
	info = read_file("/data/npc/champion_ry.o");
	if (!info) call_out("destroying", 0); 
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id!=this_player()->query("id")) call_out("destroying", 0); 
}
me = this_player();
        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("����й��������.\n");
   if( (int)me-> query_temp("number") > 0 )
     return notify_fail("�����ֻ���ٻ�һ��������ӡ�\n");
   if (me->query("jing")<100) 
	return notify_fail("�㾫������\n");
 if( !me->is_fighting() )
        return notify_fail("����û����Ҫɱ�㣡\n");
if ( me->is_busy() )
        return notify_fail("��������æ�ò����ˣ�������˼�ٻ���ĵ��ӣ�\n");
	exp = (int)me->query("combat_exp");
	me->receive_damage("jing",100);
	dizi = load_object("/d/biwu/dizi.c");
	dizi->move(environment(me));
        dizi->invocation(me, (exp));
        dizi->set("possessed", me);
	 dizi->set_name(this_player()->query("name")+"���������",({"dizi"}));
        me->add_temp("number",1);
//        me->remove_all_killer();
	message_vision(CYN "\n$N��������ٻ���ߵĵ����������Լ���\n" NOR, me);	
	message_vision(CYN "\n$N�ĵ������ź�����������\n" NOR, me);
	return 1;
}
