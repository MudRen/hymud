// score.c
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

string bar_string = "��������������������������������������������������";
string blank_string = "��������������������������������������������������";
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);


void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob, obt;
        string hymsg;
	mapping my;
	string line, str, skill_type,zs,zs1,zs2;
	object weapon;
        int attack_points, dodge_points, parry_points, btmp, t, d, r,money,i,zs3,zs4,money2;
        int a,b,c,hylv;
	seteuid(getuid(me));
        btmp=1;
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
                obt = find_player(arg);
                if ( !obt ) btmp=0;
                if (!ob) ob = obt;
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
        my = ob->query_entire_dbase();

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
	if( ob->query("mud_age") > 86400){
	t = ob->query("t");
	d = ob->query("d");
	r = ob->query("r");
	}
write("$score\n"NOR);
write(""+ob->short(1)+"\n");
write("�����꡿"+chinese_number(ob->query("age"))+"��"+chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200 + 1 )+"��"+"\n");
write("�����ա�"+CHINESE_D->chinese_date((ob->query("birthday") - 14*365*24*60) * 60-890000000)+"\n");
write("���Ա�"+ob->query("gender")+"\n");
 if( ob->query("couple/couple_name") ){
write("�����¡�"+ob->query("couple/couple_name")+"\n");
	}
else write("�����¡�"+"��\n");
	if( mapp(my["family"]) ) {
		if( my["family"]["master_name"] ){
write("��ʦ����"+my["family"]["master_name"]+"\n");
		}
else write("��ʦ����"+"��\n");
	}
if( mapp(my["family"]) ) {
		if( my["family"]["family_name"] ){
write("��ʦ�š�"+my["family"]["family_name"]+"");
if (ob->query_condition("psgc")>0)
write("��""ʦ��׷ɱ""��"+chinese_number(ob->query_condition("psgc"))+"");
write("��ʦ�Ź��ס�"+chinese_number(my["mpgx"])+"\n");
		}
else write("��ʦ�š�"+"��\n");
}
       
zs="��";
zs1="��";
zs2="";
if (ob->query("zhuanshen"))
zs="һת";
if (ob->query("zhuanbest"))
zs="��ת";
if (ob->query("4zhuan"))
zs="��ת";
if (ob->query("5zhuan"))
zs="��ת";
if (ob->query("zhuanfinal/7"))
zs1="������ʮ�����졿";
if (ob->query("zhuanfinal/8"))
zs1=zs1+" �������񹦡�";
if (ob->query("zhuanfinal/1"))
zs2="��Ԫ�����";
if (ob->query("zhuanfinal/2"))
zs2=zs2+" ����Ӱ���١�";
if (ob->query("zhuanfinal/3"))
zs2=zs2+" ����ħ����";
if (ob->query("zhuanfinal/4"))
zs2=zs2+" �����ǲ���";
if (ob->query("zhuanfinal/5"))
zs2=zs2+" ����Ԫ�󷨡�";
if (ob->query("zhuanfinal/6"))
zs2=zs2+" ����ʿ��˫��";
zs3=6000000+(ob->query("expmax",1)*500000);
zs4=ob->query_temp("menpaijob",1);
write("��ת����"+zs+"");
if (!ob->query("4zhuan"))
{
write("\n");


}
if (ob->query("4zhuan"))
{
write("����������"+zs4+"");write("���书���ޡ�"+zs3+"\n");
write("��ת�����ܡ�"+zs2+"\n");
//write("��æ��ʱ�䡿"+ob->query_busy()+"\n");

}
a=ob->query_temp("apply/damage");

if (userp(ob) && ob->query("str") && ob->query("age") >=18)
	{
		
		hylv=ob->query("age",1);
		if (hylv >30) hylv=30;
		c= ob->query("str",1)*hylv;
		if (c>3000) c=3000;
	a += c;
	}
	
b=ob->query_temp("apply/armor");
if (userp(ob) && ob->query("dex")  && ob->query("age") >=18)
	{
		
		hylv=ob->query("age",1);
		if (hylv >30) hylv=30;
		c= ob->query("dex",1)*hylv;
		if (c>3000) c=3000;
	b += c;
	}
	

write("��������"+display_attr(my["str"], ob->query_str())+"("+ob->query("str")+")"+"������������"+"(+"+a+")\n");
write("�����ԡ�"+display_attr(my["int"], ob->query_int())+"("+ob->query("int")+")"+"�����߷�����"+"(+"+b+")\n");
write("�����ǡ�"+display_attr(my["con"], ob->query_con())+"("+ob->query("con")+")"+"��ɱ��������"+chinese_number(my["MKS"] + my["PKS"])+"\n");
write("������"+display_attr(my["dex"], ob->query_dex())+"("+ob->query("dex")+")"+"��ɱ�������"+chinese_number(my["PKS"])+"\n");
if (wizardp(me)  || me->query("hyvip") || 1==1)
{
write("����Ե��"+display_attr(my["kar"], ob->query_kar())+"("+ob->query("kar")+")"+"������������"+chinese_number(my["dietimes"])+"\n");
}
else write("����Ե��"+"???"+"������������"+chinese_number(my["dietimes"])+"\n");
if (wizardp(me) || me->query("hyvip")  || 1==1)
{
write("����ò��"+display_attr(my["per"], ob->query_per())+"("+ob->query("per")+")"+"������������"+chinese_number(my["dietimes"] - my["mal_die"])+"\n");
} else write("����ò��"+"???"+"������������"+chinese_number(my["dietimes"] - my["mal_die"])+"\n");
write("������"+my["jing"]+"/"+my["max_jing"] + "����ʦ������"+chinese_number(ob->query("betrayer"))+"\n");
write("����Ѫ��"+my["qi"]+"/"+my["max_qi"] + "�����������"+chinese_number(ob->query("meili"))+"\n");
write("����ˮ��"+my["water"]+"/"+ob->max_water_capacity() + "������������"+chinese_number(ob->query("weiwang"))+"\n");
write("��ʳ�"+my["food"]+"/"+ob->max_food_capacity() + "������������"+ob->query("score")+"\n");
write("��������"+"/cmds/std/looksj.c"->getatt(ob,1)+" ");
write("��������"+"/cmds/std/looksj.c"->getdef(ob,1)+" ");
write("��������"+"/cmds/std/looksj.c"->getdog(ob,1)+"\n");
if (wizardp(me))write("����������"+attack_points/100 + 1+"(+"+ob->query_temp("apply/damage")+")\n");
if (wizardp(me))write("����������"+(dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1+"(+"+ob->query_temp("apply/armor")+")\n");
write("������������"+ob->query("shen")+"\n");
write("��ѧϰǱ����"+(ob->query("potential") - ob->query("learned_points"))+"\n");
write("��ʵս���顿"+ob->query("combat_exp")+"\n");
        if( ob->query("killbyname") && ob->query("killbyname")!="������"){
write("���ϴ�����"+"��"+ob->query("killbyname")+"ɱ��\n");
	}
        if( ob->query("killbyname") && ob->query("killbyname")=="������"){
write("���ϴ�����"+"������\n");
	}
	if (ob->query("age")==14) money = 1000;
	if (ob->query("age")>14) money = 1000 + (ob->query("age")-15) * 20;
	if (ob->query("age")>20) money = 2000 + (ob->query("age")-20) * 20;
	if (ob->query("age")>30) money = 4000 + (ob->query("age")-30) * 30;
	if (ob->query("age")>40) money = 8000 + (ob->query("age")-40) * 40;
		
	money2=(int)ob->query("balance",1);
if (money2> 10000)
{
money2=money2/10000;	
write("����ǰ��"+money2+"���ƽ�"+"\n");	
}
else
{
write("����ǰ��"+money2+"��ͭǮ"+"\n");		
}

write("��������ޡ�"+money+"���ƽ�"+"\n");
        if( !ob->query("killbyname")){
write("���ϴ�����"+"��\n");
	}
if (me->query_temp("apply/strength") > 1800)
me->set_temp("apply/strength",1800);
if (me->query_temp("apply/intelligence") > 1800)
me->set_temp("apply/intelligence",1800);
if (me->query_temp("apply/constitution") > 1800)
me->set_temp("apply/constitution",1800);
if (me->query_temp("apply/dexerity") > 1800)
me->set_temp("apply/dexerity",1800);
if (me->query_temp("apply/attack") > 1800)
me->set_temp("apply/attack",1800);
if (me->query_temp("apply/defense") > 1800)
me->set("apply/defense",1800);
if (me->query_temp("apply/damage") > 18000)
me->set_temp("apply/damage",18000);
if (me->query_temp("apply/armor") > 18500)
me->set_temp("apply/armor",18500);
if (me->query_temp("apply/dodge") > 1800)
me->set_temp("apply/dodge",1800);

hylv   = (int)ob->query("hyvip"); 
if (hylv==0) hymsg="һ�����";
if (hylv==1) hymsg="������Ա";
if (hylv==2) hymsg="�м���Ա";
if (hylv==3) hymsg="�߼���Ա";		 
if (hylv==4) hymsg="�ǻһ�Ա";
 
write("����Ա�ȼ���"+hymsg+"\n");
if ((int)ob->query("hyday")>=1000000)
{
write("����Ա������"+"�����Ա \n");
if (wizardp(ob)) write("��ʣ��������"+chinese_number(ob->query("hyday"))+"\n");	
}
else
{
write("����Ա������"+chinese_number(ob->query("hyday"))+"\n");	
}	
write("�����������"+chinese_number(ob->query("hymoney"))+"\n");


if ( (int)ob->query_condition("killer" ) > 0)
write("��ͨ��׷ɱ�� ����\n");
else
write("��ͨ��׷ɱ�� ����\n");

if ( (int)ob->query_condition("psgc" ) > 0)
write("����ʦ׷ɱ�� ����\n");
else
write("����ʦ׷ɱ�� ����\n");

if ( (int)ob->query_condition("bonze_drug" ) > 0 || (int)ob->query_condition("putizi_drug" ) > 0 || (int)ob->query_condition("medicine" ) > 0)
write("��ҩ��ҩ�ԡ� ����\n");
else
write("��ҩ��ҩ�ԡ� ����\n");
write("$#\n");
	return 1;
        
}
string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf(  "%3d" , value );
	else if( value < gift ) return sprintf( CYN "%3d" , value );
	else return sprintf("%3d", value);
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return "";
	if( percent >= 90 ) return "";
	if( percent >= 60 ) return "";
	if( percent >= 30 ) return "";
	if( percent >= 10 ) return "";
	return "";
}

int help(object me)
{
	write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ��(��)��ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��

see also : hp
HELP
    );
    return 1;
}
