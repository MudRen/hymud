// ganjiang.c  �ɽ�
// Written by Doing Lu  1998/11/2


inherit NPC;
int	weaponmake();
int	armormake();
inherit __DIR__"user_weapond.c";
#include <ansi.h>

string *typeshi2=({
RED"��Ѫʯ"NOR,
HIC"����ʯ"NOR,
MAG"ܽ��ʯ"NOR,
WHT"��ɽʯ"NOR,
GRN"����ʯ"NOR,
HIG"�⾧ʯ"NOR,
HIM"��ȸʯ"NOR,
HIB"����ʯ"NOR,
HIY"���ʯ"NOR,
});

string *typeshi1=({
HIY"��"NOR,
CYN"ľ"NOR,
GRN"ˮ"NOR,
RED"��"NOR,
YEL"��"NOR,
HIM"��"NOR,
HIW"��"NOR,
HIB"��"NOR,
WHT"��"NOR,
BBLK"��"NOR,
HIC"��"NOR,
HIR"ħ"NOR,
HIC"����"NOR,
CYN"����"NOR,
YEL"��Դ"NOR,
RED"����"NOR,
GRN"��Ԩ"NOR,
HIG"����"NOR,
WHT"��ʯ"NOR,
MAG"��ʯ"NOR,
HIC"����"NOR,
HIW"����"NOR,
HIR"����"NOR,
YEL"����"NOR,
HIY"����"NOR,
HIG"����"NOR,
GRN"����"NOR,
BLU"����"NOR,
});

void create()
{
        seteuid(getuid());

	set_name("�ɽ�", ({ "gan jiang", "ganjiang", "gan" }));
	set("long", "�����ô�׳�������������絶����͸��һ��Ӣ�������ǹ�������������������ʦ��\n" );

	set("nickname", HIR "��ʦ" NOR);
	set("gender", "����");
	set("attitude", "friendly");
  set("qi",100000);
  set("jing",100000);
  set("max_qi",100000);
  set("max_jing",100000);

  set("neili",100000);
  set("max_neili",100000);
set("combat_exp",9000000);
	set("age", 35);
	set("per", 30);
	set("shen_type", 0);
set_skill("sword",1000);
set_skill("ai-sword",1000);
map_skill("sword", "ai-sword");
	set("str", 1000);

	set("inquiry", ([
		"��������" : (: weaponmake :),
		"��������" : (: weaponmake :),
		"�������" : (: armormake :),
		"���Ʒ���" : (: armormake :),
		"makeweapon" : (: weaponmake :),
		"makearmor" : (: armormake :),
		"ԭ��" : "�����͵���ԭ�ϣ�һ��Ǯ��һ�ֻ�����ԭ�Ͼ��ܳ��ö�����\n",
		"����" : "�����ٵúܣ��������ƽ�Ҫ�������뽻��Īа��\n",
		"�۸�" : "һ��Ǯһ�ֻ�......",
		
	]));

        setup();

        set("startroom", "/d/item/jianchang");
 //       check_clone();
        if (! this_object()) return;
carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object me;

	// ���ѯ�ʱ�־
//        if (! objectp(me = this_player()) || ! interactive(me))
//                return;

	add_action("do_show", "duanlian");
	add_action("do_show2", "levelup");
	add_action("do_show2", "shenji");
  add_action("do_show", "gaizhao");


}



int do_show(string arg)
{
	object	me;
	object	ob,ob1;
	string	msg;
        string  mat;
	int	power_point;
	int	value;
	int	n;
mapping type;


	string type2;
	string type1;
	string name,wname;
	string info,id,file,infoa,infob,filen;
  object weapon,newob;
string my_file,myfile1,myfile2;
int i,lb,lv,i2,i3,i4,sharpness,lev;
	
	me = this_player();
	if (! arg)
                return notify_fail("�������ʲô���������������š���֪�����Կ�(uweapon)һ�¡�\n");

        mat = arg;
	power_point = 0;

file = "/p/residence/weapon/"+me->query("id")+"_"+arg+".c";
  newob=load_object(file);
	newob=load_object(file);
	
	if (!newob)
	return notify_fail("û��������������������\n");

sharpness=newob->query("sharpness",1);
if (sharpness>=1) lev=1;
if (sharpness>=3) lev=2;
if (sharpness>=9) lev=3;
if (sharpness>=12) lev=4;
if (sharpness>=15) lev=5;
if (sharpness>=18) lev=6;








	my_file = read_file(file);

    if(me->is_busy())
        return notify_fail("��������æ��\n");

mat = newob->query("id");

	if (! objectp(ob = present(mat, me)))
		return notify_fail("���˰ɣ�������û�� " + mat + " ���ֶ�����\n");

	if (! me->query_temp("item/upyushin"))
		return notify_fail("���˰ɣ�������û�в��ϰ���\n");

	if (! me->query_temp("item/upyushi"))
		return notify_fail("���˰ɣ�������û�в��ϰ���\n");

	lv=me->query_temp("item/upyushilv");
	if (! me->query_temp("item/upyushilv")) lv=0;


	lb=me->query_temp("item/upyushilb");
	if (! me->query_temp("item/upyushilb")) lb=0;

		type2=typeshi2[lb];
type1=typeshi1[lv];
wname=ob->query("name");

	if (! wname)
		return notify_fail("���˰ɣ�������û�в��ϰ���\n");

	message_vision("$N��$n˵����" 
		//"����Ҫ�����������" +wname+ "�ɣ�\n",
		"���Ϊ:" +type1 + " �ȼ�Ϊ" +type2 + "��\n",
 this_object(), this_player());

message_vision(HIC "\n$N˵�����ã���¯������\n\n" NOR, this_object(),me);
	message_vision(HIM "$N�ӹ�Īа���еĲ���"
		       HIM "�����ְ�������¯�ڣ���ʱ�䣬��Щ����"
		       HIM "�ѱ���¯�е�����" HIR "����" HIM "��û��\n" +
		       "$N������¯����˵�������֮����Ϊ��Ѫ������"
                       "��֮�����������......\n" NOR , this_object(),me);

	

me->set_temp("paid/moye2",0);
me->delete_temp("item/upyushin");
me->delete_temp("item/upyushi");
me->delete_temp("item/upyushilv");
me->delete_temp("item/upyushilb");


//if (random(3)==0 || wizardp(me))
if (random(3)==0 || me->query_temp("dlwok"))
{
		message_vision(HIW "$N˵������ж���ʯ�����á�\n" NOR,this_object(),me);

		message_vision(HIW "$N�����Ĵ�ˮ�س�������õ�" + wname +
		       HIW "���˿��������˵���ܺã��ܺá�\n" + wname +HIW"��" +type1 + HIW"���Է����˸ı䡣\n" NOR,this_object(),me);
me->set_temp("dlwok",0);
me->delete_temp("dlwok");
}
else
{
		message_vision(HIR "$N�����Ĵ�ˮ�س�������õ�" + wname +
		       HIR "���˿���̾�˿���˵����򲻹�......ʱ������......\n\n" NOR,this_object(),me);

i3=1+(lb*2);
wname=ob->query("name");
if (!newob->query("armor_type"))
{
  i2=newob->query("weapon_prop/damage")+i3;
if (i2 < 5000)
{
	myfile1="init_"+newob->query("skill_type")+"("+newob->query("weapon_prop/damage")+")";
  myfile2="init_"+newob->query("skill_type")+"("+i2+")";
my_file= replace_string(my_file,myfile1,myfile2);	
write_file(file,my_file,1);
destruct(newob);
newob=load_object(file);
		message_vision(HIW "$N̾�˿���˵" + wname +
		       HIR "��Ȼʧ����,����ԭ����ʵһЩ,�ܲ�����һ������......\n\n" NOR,this_object(),me);
if (present(newob->query("id"),me)) destruct(present(newob->query("id"),me));
destruct(newob);
newob=load_object(file);
newob->move(me);
return 1;	
}
}
else
{
i2=newob->query("armor_prop/armor")+i3;
i4=0;
if (newob->query("armor_prop/damage")) i4=newob->query("armor_prop/damage")+i3;
if (i2 < 5000)
{
myfile1="set(\"armor_prop/armor\", "+newob->query("armor_prop/armor")+")";
myfile2="set(\"armor_prop/armor\", "+i2+")";
my_file= replace_string(my_file,myfile1,myfile2);	
write_file(file,my_file,1);

if (newob->query("armor_prop/damage") && i4 < 5000) 
{
myfile1="set(\"armor_prop/damage\", "+newob->query("armor_prop/damage")+")";
myfile2="set(\"armor_prop/damage\", "+i4+")";
my_file= replace_string(my_file,myfile1,myfile2);	
write_file(file,my_file,1);
}

destruct(newob);
newob=load_object(file);
		message_vision(HIW "$N̾�˿���˵" + wname +
		       HIR "��Ȼʧ����,����ԭ����ʵһЩ,�ܲ�����һ������......\n\n" NOR,this_object(),me);
if (present(newob->query("id"),me)) destruct(present(newob->query("id"),me));
destruct(newob);
newob=load_object(file);
newob->move(me);
return 1;	
}
}

	return 1;	
}	
i=1+lb;

if (lev <=5 && i>7) i=7;
if (lev <=4 && i>6) i=6;
if (lev <=3 && i>5) i=5;
if (lev <=2 && i>3) i=3;


i2=i*8;



if (lv >11) lv=lv+1;
if (!newob->query("armor_type"))
{

if (lv==13)
{
myfile1="set(\"weapon_prop/intelligence\","+newob->query("weapon_prop/intelligence")+")";
myfile2="set(\"weapon_prop/intelligence\","+i2+")";
if (i2>newob->query("weapon_prop/intelligence"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==14)
{
myfile1="set(\"weapon_prop/strength\","+newob->query("weapon_prop/strength")+")";
myfile2="set(\"weapon_prop/strength\","+i2+")";
if (i2>newob->query("weapon_prop/strength"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==15)
{
myfile1="set(\"weapon_prop/karey\","+newob->query("weapon_prop/karey")+")";
myfile2="set(\"weapon_prop/karey\","+i2+")";
if (i2>newob->query("weapon_prop/karey"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==16)
{
myfile1="set(\"weapon_prop/percao\","+newob->query("weapon_prop/percao")+")";
myfile2="set(\"weapon_prop/percao\","+i2+")";
if (i2>newob->query("weapon_prop/percao"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==17)
{
myfile1="set(\"weapon_prop/dexerity\","+newob->query("weapon_prop/dexerity")+")";
myfile2="set(\"weapon_prop/dexerity\","+i2+")";
if (i2>newob->query("weapon_prop/dexerity"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==18)
{
myfile1="set(\"weapon_prop/constitution\","+newob->query("weapon_prop/constitution")+")";
myfile2="set(\"weapon_prop/constitution\","+i2+")";
if (i2>newob->query("weapon_prop/constitution"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==19)
{
myfile1="set(\"weapon_prop/dodge\", 0)";
myfile2="set(\"weapon_prop/dodge\", "+i2+")";
if (i2>newob->query("weapon_prop/dodge"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==20)
{
myfile1="set(\"weapon_prop/parry\", "+newob->query("weapon_prop/parry")+")";
myfile2="set(\"weapon_prop/parry\", "+i2+")";
if (i2>newob->query("weapon_prop/parry"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==21)
{
myfile1="set(\"weapon_prop/attack\", "+newob->query("weapon_prop/attack")+")";
myfile2="set(\"weapon_prop/attack\", "+i2+")";
if (i2>newob->query("weapon_prop/attack"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==22)
{
myfile1="set(\"weapon_prop/armor\", "+newob->query("weapon_prop/armor")+")";
myfile2="set(\"weapon_prop/armor\", "+i2+")";
if (i2>newob->query("weapon_prop/armor"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==23)
{
myfile1="set(\"weapon_prop/defense\", "+newob->query("weapon_prop/defense")+")";
myfile2="set(\"weapon_prop/defense\", "+i2+")";
if (i2>newob->query("weapon_prop/defense"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==24)
{
myfile1="set(\"weapon_prop/neili\", "+newob->query("weapon_prop/neili")+")";
myfile2="set(\"weapon_prop/neili\", "+i2+")";
if (i2>newob->query("weapon_prop/neili"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==25)
{
myfile1="set(\"weapon_prop/qi\", "+newob->query("weapon_prop/qi")+")";
myfile2="set(\"weapon_prop/qi\", "+i2+")";
if (i2>newob->query("weapon_prop/qi"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==26)
{
myfile1="set(\"weapon_prop/jing\", "+newob->query("weapon_prop/jing")+")";
myfile2="set(\"weapon_prop/jing\", "+i2+")";
if (i2>newob->query("weapon_prop/jing"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==27)
{
myfile1="set(\"weapon_prop/jingli\", "+newob->query("weapon_prop/jingli")+")";
myfile2="set(\"weapon_prop/jingli\", "+i2+")";
if (i2>newob->query("weapon_prop/jingli"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==28)
{
myfile1="set(\"weapon_prop/damage\", 0)";
myfile2="set(\"weapon_prop/damage\", "+i2+")";
my_file= replace_string(my_file,myfile1,myfile2);	

}


}
else
{


if (lv==13)
{
myfile1="set(\"armor_prop/intelligence\","+newob->query("armor_prop/intelligence")+")";
myfile2="set(\"armor_prop/intelligence\","+i2+")";
if (i2>newob->query("armor_prop/intelligence"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==14)
{
myfile1="set(\"armor_prop/strength\","+newob->query("armor_prop/strength")+")";
myfile2="set(\"armor_prop/strength\","+i2+")";
if (i2>newob->query("armor_prop/strength"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==15)
{
myfile1="set(\"armor_prop/karey\","+newob->query("armor_prop/karey")+")";
myfile2="set(\"armor_prop/karey\","+i2+")";
if (i2>newob->query("armor_prop/karey"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==16)
{
myfile1="set(\"armor_prop/percao\","+newob->query("armor_prop/percao")+")";
myfile2="set(\"armor_prop/percao\","+i2+")";
if (i2>newob->query("armor_prop/percao"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==17)
{
myfile1="set(\"armor_prop/dexerity\","+newob->query("armor_prop/dexerity")+")";
myfile2="set(\"armor_prop/dexerity\","+i2+")";
if (i2>newob->query("armor_prop/dexerity"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==18)
{
myfile1="set(\"armor_prop/constitution\","+newob->query("armor_prop/constitution")+")";
myfile2="set(\"armor_prop/constitution\","+i2+")";
if (i2>newob->query("armor_prop/constitution"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==19)
{
myfile1="set(\"armor_prop/dodge\", "+newob->query("armor_prop/dodge")+")";
myfile2="set(\"armor_prop/dodge\", "+i2+")";
if (i2>newob->query("armor_prop/dodge"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==20)
{
myfile1="set(\"armor_prop/parry\", "+newob->query("armor_prop/parry")+")";
myfile2="set(\"armor_prop/parry\", "+i2+")";
if (i2>newob->query("armor_prop/parry"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==21)
{
myfile1="set(\"armor_prop/attack\", "+newob->query("armor_prop/attack")+")";
myfile2="set(\"armor_prop/attack\", "+i2+")";
if (i2>newob->query("armor_prop/attack"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==22)
{
myfile1="set(\"armor_prop/armor\", "+newob->query("armor_prop/armor")+")";
myfile2="set(\"armor_prop/armor\", "+i2+")";
if (i2>newob->query("armor_prop/armor"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==23)
{
myfile1="set(\"armor_prop/defense\", "+newob->query("armor_prop/defense")+")";
myfile2="set(\"armor_prop/defense\", "+i2+")";
if (i2>newob->query("armor_prop/defense"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==24)
{
myfile1="set(\"armor_prop/neili\", "+newob->query("armor_prop/neili")+")";
myfile2="set(\"armor_prop/neili\", "+i2+")";
if (i2>newob->query("armor_prop/neili"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==25)
{
myfile1="set(\"armor_prop/qi\", "+newob->query("armor_prop/qi")+")";
myfile2="set(\"armor_prop/qi\", "+i2+")";
if (i2>newob->query("armor_prop/qi"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==26)
{
myfile1="set(\"armor_prop/jing\", "+newob->query("armor_prop/jing")+")";
myfile2="set(\"armor_prop/jing\", "+i2+")";
if (i2>newob->query("armor_prop/jing"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==27)
{
myfile1="set(\"armor_prop/jingli\", "+newob->query("armor_prop/jingli")+")";
myfile2="set(\"armor_prop/jingli\", "+i2+")";
if (i2>newob->query("armor_prop/jingli"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==28)
{
myfile1="set(\"armor_prop/damage\", "+newob->query("armor_prop/damage")+")";
myfile2="set(\"armor_prop/damage\", "+i2+")";
if (i2>newob->query("armor_prop/damage"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

}

if (lv==0)
{
myfile1="set(\"wtypeA\","+newob->query("wtypeA")+")";
myfile2="set(\"wtypeA\","+i+")";
if (i2>newob->query("wtypeA"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==1)
{
myfile1="set(\"wtypeB\","+newob->query("wtypeB")+")";
myfile2="set(\"wtypeB\","+i+")";
if (i2>newob->query("wtypeB"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==2)
{
myfile1="set(\"wtypeC\","+newob->query("wtypeC")+")";
myfile2="set(\"wtypeC\","+i+")";
if (i2>newob->query("wtypeC"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==3)
{
myfile1="set(\"wtypeD\","+newob->query("wtypeD")+")";
myfile2="set(\"wtypeD\","+i+")";
if (i2>newob->query("wtypeD"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==4)
{
myfile1="set(\"wtypeE\","+newob->query("wtypeE")+")";
myfile2="set(\"wtypeE\","+i+")";
if (i2>newob->query("wtypeE"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==5)
{
myfile1="set(\"wtypeF\","+newob->query("wtypeF")+")";
myfile2="set(\"wtypeF\","+i+")";
if (i2>newob->query("wtypeF"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==6)
{
myfile1="set(\"wtypeG\","+newob->query("wtypeG")+")";
myfile2="set(\"wtypeG\","+i+")";
if (i2>newob->query("wtypeG"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==7)
{
myfile1="set(\"wtypeH\","+newob->query("wtypeH")+")";
myfile2="set(\"wtypeH\","+i+")";
if (i2>newob->query("wtypeH"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==8)
{
myfile1="set(\"wtypeI\","+newob->query("wtypeI")+")";
myfile2="set(\"wtypeI\","+i+")";
if (i2>newob->query("wtypeI"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==9)
{
myfile1="set(\"wtypeJ\","+newob->query("wtypeJ")+")";
myfile2="set(\"wtypeJ\","+i+")";
if (i2>newob->query("wtypeJ"))
my_file= replace_string(my_file,myfile1,myfile2);	
}

if (lv==10)
{
myfile1="set(\"wtypeK\","+newob->query("wtypeK")+")";
myfile2="set(\"wtypeK\","+i+")";
if (i2>newob->query("wtypeK"))
my_file= replace_string(my_file,myfile1,myfile2);	
}


if (lv==11)
{
myfile1="set(\"wtypeL\","+newob->query("wtypeL")+")";
myfile2="set(\"wtypeL\","+i+")";
if (i2>newob->query("wtypeL"))
my_file= replace_string(my_file,myfile1,myfile2);	
}




write_file(file,my_file,1);
destruct(newob);
newob=load_object(file);
message_vision(HIR "$N˫��һչ һ"+newob->query("unit")+newob->query("name")+"("+newob->query("id")+")"+HIR" ������г�����$N���ϡ�\n" NOR, me);
if (present(newob->query("id"),me)) destruct(present(newob->query("id"),me));
destruct(newob);
newob=load_object(file);
newob->move(me);

return 1;	
	


}



int do_show2(string arg)
{
	object	me;
	object	ob,ob1;
	string	msg;
        string  mat;
	int	power_point;
	int	value;
	int	n;
mapping type;


	//string type2;
	//string type1;
	string name,wname;
	string info,id,file,infoa,infob,filen;
  object weapon,newob;
string my_file,myfile1,myfile2;
int i,lb,lv,i2,i3,i4,sharpness,lev,sharpness2;
	
	me = this_player();
	if (! arg)
                return notify_fail("�������ʲô���������������š���֪�����Կ�(uweapon)һ�¡�\n");

        mat = arg;
	power_point = 0;

file = "/p/residence/weapon/"+me->query("id")+"_"+arg+".c";
  newob=load_object(file);
	newob=load_object(file);
	
	if (!newob)
	return notify_fail("û��������������������\n");

sharpness=newob->query("sharpness",1);
if (sharpness>=1) 
{
lev=1;
sharpness2=3;
}

if (sharpness>=3) 
{
	lev=2;
sharpness2=9;
}
	
if (sharpness>=9) {
	lev=3;
sharpness2=12;
}

if (sharpness>=12)
{
 lev=4;
sharpness2=15;
}

if (sharpness>=15)
{
 lev=5;
sharpness2=18;
}

if (sharpness>=18)
{
 lev=6;
sharpness2=20;
}


if (sharpness>=20)
{
 lev=7;
sharpness2=22;
}

if (sharpness>=22)
{
 lev=8;
sharpness2=24;
}

if (sharpness>=24)
{
 lev=9;
sharpness2=24;
}

	my_file = read_file(file);

    if(me->is_busy())
        return notify_fail("��������æ��\n");

mat = newob->query("id");
wname = newob->query("name");
	if (! objectp(ob = present(mat, me)))
		return notify_fail("���˰ɣ�������û�� " + mat + " ���ֶ�����\n");

	if (! me->query_temp("lvsjok"))
		return notify_fail("���˰ɣ�������û�в��ϰ���\n");


	if ( lev>8)
		return notify_fail("���˰ɣ����װ��û�취�������ˡ�\n");


	message_vision("$N��$n˵����" 
		//"����Ҫ�����������" +wname+ "�ɣ�\n",
		" Ʒ��Ϊ" +lev + "��\n",
 this_object(), this_player());

message_vision(HIC "\n$N˵�����ã���¯������\n\n" NOR, this_object(),me);
	message_vision(HIM "$N�ӹ�Īа���еĲ���"
		       HIM "�����ְ�������¯�ڣ���ʱ�䣬��Щ����"
		       HIM "�ѱ���¯�е�����" HIR "����" HIM "��û��\n" +
		       "$N������¯����˵�������֮����Ϊ��Ѫ������"
                       "��֮�����������......\n" NOR , this_object(),me);

	

me->set_temp("lvsjok",0);
me->delete_temp("lvsjok");


//if (random(3)==0 || wizardp(me))

		//message_vision(HIW "$N˵������ж���ʯ�����á�\n" NOR,this_object(),me);

		message_vision(HIW "$N�����Ĵ�ˮ�س�������õ�" + wname +
		       HIW "���˿��������˵���ܺã��ܺá�\n" + wname +HIW"��Ʒ�ʷ����˸ı䡣\n" NOR,this_object(),me);

i3=20+(lev*60);
//wname=ob->query("name");

if (!newob->query("armor_type"))
{
  i2=newob->query("weapon_prop/damage")+i3;
if (i2 < 5000)
{
	myfile1="init_"+newob->query("skill_type")+"("+newob->query("weapon_prop/damage")+")";
  myfile2="init_"+newob->query("skill_type")+"("+i2+")";
my_file= replace_string(my_file,myfile1,myfile2);	
write_file(file,my_file,1);
}
}
else
{
i2=newob->query("armor_prop/armor")+i3;
i4=0;
if (newob->query("armor_prop/damage")) i4=newob->query("armor_prop/damage")+(i3/2+1);

if (i2 < 5000)
{
myfile1="set(\"armor_prop/armor\", "+newob->query("armor_prop/armor")+")";
myfile2="set(\"armor_prop/armor\", "+i2+")";
my_file= replace_string(my_file,myfile1,myfile2);	
write_file(file,my_file,1);

if (newob->query("armor_prop/damage") && i4 < 5000) 
{
myfile1="set(\"armor_prop/damage\", "+newob->query("armor_prop/damage")+")";
myfile2="set(\"armor_prop/damage\", "+i4+")";
my_file= replace_string(my_file,myfile1,myfile2);	
write_file(file,my_file,1);
}

	
}
}

 //set("sharpness", 2);

myfile1="set(\"sharpness\", "+sharpness+")";
myfile2="set(\"sharpness\", "+sharpness2+")";
my_file= replace_string(my_file,myfile1,myfile2);	
write_file(file,my_file,1);
//destruct(newob);

newob=load_object(file);
message_vision(HIR "$N˫��һչ һ"+newob->query("unit")+newob->query("name")+"("+newob->query("id")+")"+HIR" ������г�����$N���ϡ�\n" NOR, me);
if (present(newob->query("id"),me)) destruct(present(newob->query("id"),me));
destruct(newob);
newob=load_object(file);
newob->move(me);


return 1;	

}






        