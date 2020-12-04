// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit NPC;
mapping valid_typesw = ([
	"sword":	"sword",
	"blade":	"blade",
	"hammer":	"hammer",
	"whip":     "whip",
	"club":     "club",
	"staff":     "staff",
	"throwing":     "throwing",
	"dagger":     "dagger",			
"axe":     "axe",				
]);

mapping valid_typesa = ([
	"hands":	"hands",
	"cloth":	"cloth",
	"armor":	"armor",
	"boots":     "boots",
	"head":     "head",
	"neck":     "neck",
	"surcoat":     "surcoat",
	"shield":     "shield",			
"waist":     "waist",		
"wrists":     "wrists",			
]);



string *typew=({
"sword",
"blade",
"hammer",
"whip",
"club",
"staff",
"throwing",
"dagger",
"axe",
});
string *typea=({
"hands",
"cloth",
"armor",
"boots",
"head",
"neck",
"surcoat",
"shield",
"waist",
"wrists",
});
int ask_hygoods();
int ask_hygoods2();
int ask_pk();
int ask_newbie2();
string ask_liwu15();
private string chinese_types(string types)
{
        switch(types)
        {
        case "object"             :    return HIC "��Ʒ" NOR;
        case "objamount"          :    return HIC "��Ʒ" NOR;
        case "special"            :    return HIG "���⼼��" NOR;
        case "special2"           :    return HIW "ת������" NOR;
        case "story"              :    return HIM "����" NOR;
        case "package"            :    return HIR "��" NOR;
        case "card"               :    return HIY "��" NOR;
        case "gold"               :    return HIY "��" NOR;
        default                   :    return HIR "δ֪" NOR;
        }
}

mapping goods = ([
        "besttz"  : "������װ:50:/clone/buy/object:package:���Լӳ���װ�˼� �����ð� ��������Լ�������������",	
        "money"  : "ǧ���ƽ�:5:/clone/buy/object:package:��ǧ���ƽ�",	
        "item2"  : "���������װ:5:/clone/buy/kardan:package:�������װ��һ�� �������ð�",				
        "ring2"  : "��������ָ:5:/clone/buy/kardan:package:�����ָһ�� �������ð�",					        	
        "update2"  : "����������ʯ:10:/clone/buy/kardan:package:�������������ʯһ��",					        	        			        	
        "dzshi2"  : "ұ��ʯ:15:/clone/buy/dzshi2:object:ָ�������װ������(���ε�½1��)",
        "pzshi"  : "Ʒ��ʯ:50:/clone/buy/pzshi:object:�������ָ������װ��Ʒ�ʻ���(���ε�½1��)",
        "weapon1"  : "�������:5:/clone/buy/kardan:package:����ɰ�����һ��",			
        "cloth1"  : "�������:5:/clone/buy/kardan:package:����ɰ󶨷���һ��",				
        "weapon12"  : "����м�����:10:/clone/buy/kardan:package:����ɰ����� �м�",			
        "weapon13"  : "����߼�����:20:/clone/buy/kardan:package:����ɰ����� �߼�",			
        "weapon14"  : "�����������:40:/clone/buy/kardan:package:����ɰ����� ����",			
        "cloth12"  : "����м�����:10:/clone/buy/kardan:package:����ɰ󶨷��� �м�",				
        "cloth13"  : "����߼�����:20:/clone/buy/kardan:package:����ɰ󶨷��� �߼�",				
        "cloth14"  : "�����������:40:/clone/buy/kardan:package:����ɰ󶨷��� ����",				
        "tzweapon"  : "�����װ����:50:/clone/buy/kardan:package:����ɰ����� ��װ",				
        "tzcloth"   : "�����װ����:50:/clone/buy/kardan:package:����ɰ󶨷��� ��װ",				
        "jyszhb"   : "�������ջ�������:158:/clone/buy/kardan:package:�����澭���ջ������ܳɹ�",	
        "update23"  : "������ʯ��:10:/clone/buy/kardan:package:���������ʯ�ȼ���",
        "update24"  : "������ʯ��:20:/clone/buy/kardan:package:���������ʯ�ȼ���",
        "update25"  : "������ʯ��:30:/clone/buy/kardan:package:���������ʯ�ȼ���",
        "update26"  : "������ʯ��:40:/clone/buy/kardan:package:���������ʯ�ȼ���",
        "update27"  : "������ʯ��:50:/clone/buy/kardan:package:���������ʯ�ȼ���",
        "update28"  : "������ʯ��:60:/clone/buy/kardan:package:���������ʯ�ȼ���",
        "update29"  : "������ʯ��:80:/clone/buy/kardan:package:���������ʯ�ȼ���",                
        "dzshi"  : "����ʯ:12:/clone/buy/dzshi:object:����������������100%�ɹ�(���ε�½1��)",
        "dzshi3"  : "����ʯ:30:/clone/buy/dzshi3:object:ָ������������ʯ����(���ε�½1��)",
"weapon2"  : "������������:10:/clone/buy/kardan:package:���������������һ��, �ȼ���Ϊ���",					        	        		
"weapon24"  : "��������������:20:/clone/buy/kardan:package:���ĵȼ�������������һ��",
"weapon25"  : "��������������:30:/clone/buy/kardan:package:����ȼ�������������һ��",
"weapon26"  : "��������������:40:/clone/buy/kardan:package:�����ȼ�������������һ��",
"weapon27"  : "��������������:60:/clone/buy/kardan:package:���ߵȼ�������������һ��",
"weapon28"  : "�����������ϰ�:80:/clone/buy/kardan:package:�ڰ˵ȼ�������������һ��",
"weapon29"  : "�����������Ͼ�:90:/clone/buy/kardan:package:�ھŵȼ�������������һ��",
"weapon2A"  : "������������ʮ:100:/clone/buy/kardan:package:��ʮ�ȼ�������������һ��",
"cloth2"  : "������߲���:10:/clone/buy/kardan:package:���������߲���һ��, �ȼ���Ϊ���",					        	        			        	
"cloth24"  : "������߲�����:20:/clone/buy/kardan:package:���ĵȼ�������߲���һ��",
"cloth25"  : "������߲�����:30:/clone/buy/kardan:package:����ȼ�������߲���һ��",
"cloth26"  : "������߲�����:40:/clone/buy/kardan:package:�����ȼ�������߲���һ��",
"cloth27"  : "������߲�����:60:/clone/buy/kardan:package:���ߵȼ�������߲���һ��",
"cloth28"  : "������߲��ϰ�:80:/clone/buy/kardan:package:�ڰ˵ȼ�������߲���һ��",
"cloth29"  : "������߲��Ͼ�:90:/clone/buy/kardan:package:�ھŵȼ�������߲���һ��",
"cloth2A"  : "������߲���ʮ:100:/clone/buy/kardan:package:��ʮ�ȼ�������߲���һ��",
"yu23"  : "����������ʯ��:60:/clone/buy/kardan:package:������ʯ���ϵȼ���",
"yu24"  : "����������ʯ��:80:/clone/buy/kardan:package:������ʯ���ϵȼ���",
"yu25"  : "����������ʯ��:90:/clone/buy/kardan:package:������ʯ���ϵȼ���",
"yu26"  : "����������ʯ��:100:/clone/buy/kardan:package:������ʯ���ϵȼ���",
"yu202"  : "���������ʯ:10:/clone/buy/kardan:package:���������ʯ����һ��",					        	        			        	
"yu232"  : "���������ʯ��:50:/clone/buy/kardan:package:����ʯ���ϵȼ���",
"yu242"  : "���������ʯ��:80:/clone/buy/kardan:package:����ʯ���ϵȼ���",
"yu252"  : "���������ʯ��:90:/clone/buy/kardan:package:����ʯ���ϵȼ���",
"yu262"  : "���������ʯ��:100:/clone/buy/kardan:package:����ʯ���ϵȼ���",


]);



string get_types(string arg)
{
        string strtmp;
        mixed * items;

        strtmp = goods[arg];
        items = explode(strtmp, ":");

        return items[3];
}
int sort_object(string str1, string str2)
{
        if( get_types(str1) == "package" ) return 1;
        if( get_types(str2) == "package" ) return -1;

        if( get_types(str1) == "objamount" ) return 1;
        if( get_types(str2) == "objamount" ) return -1;

        if( get_types(str1) == "object" ) return 1;
        if( get_types(str2) == "object" ) return -1;

        if( get_types(str1) == "story" ) return 1;
        if( get_types(str2) == "story" ) return -1;

        if( get_types(str1) == "special" ) return 1;
        if( get_types(str2) == "special" ) return -1;

        if( get_types(str1) == "special2" ) return 1;
        if( get_types(str2) == "special2" ) return -1;
        
        if( get_types(str1) == "card" ) return 1;
        if( get_types(str2) == "card" ) return -1;

        if( get_types(str1) == "gold" ) return 1;
        if( get_types(str2) == "gold" ) return -1;

        return -1;
}

public varargs void show_goods(string arg)
{
        string strtmp;
        int i, j;
        mixed * obs, all, items;

        obs = keys(goods);

        all = unique_array(obs, (:  get_types($1) == "objamount" ? 1 : get_types($1) == "object" ? 2 :
                                    get_types($1) == "story" ? 3 : get_types($1) == "special" ? 4 :
                                    get_types($1) == "special2" ? 5 : get_types($1) == "card" ? 6 : 
                                    get_types($1) == "package" ? 7 : 8 :));

        all = sort_array(all, (: sort_object($1[0], $2[0]) :));

        write(HIY "��Ա�̵�Ŀǰ�������»��\n" NOR);
        write(sprintf(HIW "%-16s%-16s%-10s%-10s%s\n" NOR,
                      "����", "����", "�۸�($HY)", "����", "��Ҫ˵��"));
        write(HIG "-------------------------------------------------------------------------------\n\n" NOR);

        for (i = 0; i < sizeof(all); i ++)
        {
                strtmp = "";
                items = ({});

                for(j = 0; j < sizeof(all[i]); j ++)
                {
                        strtmp = goods[all[i][j]];
                        items = explode(strtmp, ":");
                        if (sizeof(items) != 5)
                        {
                                write("strtmp made items != 5 is : " + strtmp + "\n");
                                return;
                        }
                        write(sprintf(HIW "%-16s%-16s" HIY "%-10s" HIW "%-26s%-50s\n" NOR,
                                      items[0], all[i][j], items[1], chinese_types(items[3]), items[4]));
                }
        }

        write(HIG "����ָ��" HIY ":" HIG "buygoods ����\n" NOR);
        write(HIG "�����������" HIY "��" HIG "��ǵķ����Ϊ�����Ա���ޡ�\n" NOR);
        write(HIG "�������Ķ��й�˵��������ǰ�뿼������� ���޲��ˡ���˻���\n" NOR);
        write(HIG "-------------------------------------------------------------------------------\n\n" NOR);
}


void create()
{
        set_name("����", ({ "nan xian", "nan", "xian", "nanxian" }));
        set("long", @LONG
����������ɼ���뷢�԰ס�������ò���ʵ
ȴΪ����ͷ���������������кųơ�����
���󡹵����͡���Ϊ��������а������ʱ����
�����������춯�صĴ�١���ƽ��ս��������
�ڱ�������ʧ���֡�
LONG);
        set("nickname", HIW "��������" NOR);
        set("title", HIC "����̩��" NOR);
        set("gender", "����" );
        set("age", 74);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
   set("no_kill",1);
	    set("qi",   99999999);
	    set("jing", 99999999);
	set("eff_qi",   99999999);
	set("eff_jing", 99999999);
	set("max_qi",   99999999);
	set("max_jing", 99999999);
	set("neili", 554500);
	set("max_neili", 554500);
	set("jiali", 0);
	set("combat_exp", 85000000);
	set("score", 50000);                
        set_skill("strike",1200);
        set_skill("unarmed",1200);
        set_skill("dodge",1200);
        set_skill("force", 1200);
        set_skill("unarmed", 1200);
        set_skill("sword", 1200);
	set_skill("parry", 1210);
	set_skill("literate", 1200);
	set_skill("canzhi-duanhun",1300);
	set_skill("ai-sword",1300);
        map_skill("unarmed", "canzhi-duanhun");
        map_skill("parry", "canzhi-duanhun");
        map_skill("sword", "ai-sword");

        set("inquiry", ([
                "name" : "����������һ�ִ��Ŷ��ѣ������к����壿",
                "����" : "�㾡���Ǹ������ļһ�������",
                "����" : "����(buygoods)���԰�!",	
                "��ս": (: ask_pk :),
                "challenge": (: ask_pk :),	
                "����": (: ask_newbie2 :),
                "newbie": (: ask_newbie2 :),	
                "��תѡ��": (: ask_hygoods2 :),
                "4zchoose": (: ask_hygoods2 :),	
                "��Ա��Ʒ": (: ask_hygoods :),
                "membergoods": (: ask_hygoods :),	
"job" : (: ask_liwu15 :),
        ]));

set_temp("apply/intelligence", 200);
set_temp("apply/strength",200);
set_temp("apply/dexerity",200);
set_temp("apply/constitution",200);
set_temp("apply/karey", 200);
set_temp("apply/percao", 200);	
set_temp("apply/armor", 5000);
set_temp("apply/defense", 200);
set_temp("apply/attack", 200);
set_temp("apply/damage", 5000);  
            
       	setup();
     carry_object("/clone/weapon/changjian")->wield();
          carry_object("/clone/misc/cloth")->wear();


        /*
        if (! clonep(this_object()))
        {
                move("/d/city/wumiao");
                message_vision(WHT "\nͻȻ������ǰһ��������ƺ����˸�"
                               "��Ӱ��\n" NOR, this_object());
                set("startroom", "/d/city/wumiao");
        }
        */
        set("startroom", "/d/city/wumiao");

}
void init()
{
	add_action("buy_goods", "buygoods");
	 add_action("do_answer", "answer");
}


int ask_hygoods()
{
    string week, month, year, day, time,hydata;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
 	object me = this_player();
show_goods();
        return 1;
}

int ask_hygoods2()
{
    string week, month, year, day, time,hydata;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
 	object me = this_player();
if (me->query("hyvip") < 4)
{
write("�Բ���ֻ�йǻһ�Ա�������ܴ˷�����μ� " HIR "help member " NOR " ��\n");
                return 1;	
}
if (!me->query("4zhuan") && !me->query("5zhuan"))
        {
write("�Բ���ֻ����ת����ת��Ա�������ܴ˷���\n");
                return 1;	
        }


if (me->query("zhuanfinal/7",1)==1 && me->query_skill("yinyang-shiertian",1) >=1)
{
me->delete("zhuanfinal/7");
me->delete_skill("yinyang-shiertian");
me->set("zhuanfinal/8",1);
me->set_skill("never-defeated",105);
write(HIY"ת�� ����书�������񹦡�!\n"NOR);
tell_object(me, HIR "������ƺ��Լ������˱仯��\n" NOR);
}
else if (me->query("zhuanfinal/8",1)==1  && me->query_skill("never-defeated",1) >=1)
{
me->delete("zhuanfinal/8");
me->delete_skill("never-defeated");
me->set("zhuanfinal/7",1);
me->set_skill("yinyang-shiertian",105);
write(HIY"ת�� ����书������ʮ�����졿!\n"NOR);
tell_object(me, HIR "������ƺ��Լ������˱仯��\n" NOR);
}
        return 1;
}




public int buy_goods(string which)
{
        mixed * all, items;
        mixed specials;
        string strtmp;
        int i, vip, value, money;
        object buy_ob;
        object who,me;
        object *team;
int count=0,minexp,maxexp,a,exp,pot;
int ckiller,rn;
string where;
string file;
string *roomlines;
string location;
int mi,yi,yai,lv,lb,ayai;

object ob=this_player();
        /*if (!ob->query("hyvip"))
        {
                write("�Բ���ֻ�л�Ա�������ܴ˷�����μ� " HIR "help member " NOR " ��\n");
                return 1;
        }*/


        all = keys(goods);
        if (member_array(which, all) == -1)
        {
                write("�Բ���û����Ҫ�������Ʒ " + HIR + which + NOR + "�� ����һ��"
                      "�Ұ�(ask nanxian about ��Ա��Ʒ) ��\n" NOR);
                return 1;

        }

        strtmp = goods[which];
        items = explode(strtmp, ":");
        sscanf(items[1], "%d", value);

        if (items[2] == "manual")
        {
                write("�Բ��𣬸÷�������� admin �ֶ�ʵ�֣��뼰ʱ�� admin ��ϵ��\n");
                return 1;
        }

        vip   = ob->query("hyvip");
        money = ob->query("hymoney");

        // ��Ա�ۿ�

        if (vip == 4)
                value = value * 80 / 100;
        else
        if (vip == 3)
                value = value * 85 / 100;
        else
        if (vip == 2)
                value = value * 90 / 100;

        if (value < 1) value = 1;
        if (!value) value = 1;

        if ((int)ob->query("hymoney") < 1)
        {
                write("�Բ������ĺ���������������\n");
                return 1;
        }

        if (money < value)
        {
                write("�Բ������ĺ���������������\n");
                return 1;
        }


mi=1;
if (random(4)==0) mi=2;
if (random(8)==0) mi=3;
if (random(16)==0) mi=4;
if (random(32)==0) mi=5;
if (random(64)==0) mi=6;	
if (random(128)==0) mi=7;
if (random(256)==0) mi=8;
if (random(512)==0) mi=9;
if (random(1024)==0) mi=10;				

yi=1;
if (random(8)==0) yi=2;
if (random(16)==0) yi=3;
if (random(32)==0) yi=4;
if (random(64)==0) yi=5;
if (random(128)==0) yi=6;	

yai=7;
if (random(8)==0) yai=8;
if (random(16)==0) yai=9;
if (random(32)==0) yai=10;
if (random(64)==0) yai=11;
if (random(128)==0) yai=12;	


if (random(2)==0)
{
	if (mi> 6) mi=6;
	if (yi> 4) yi=4;
	if (yai> 10) yai=10;
}

if (random(3)==0)
{
	if (mi> 5) mi=5;
	if (yi> 3) yi=3;
	if (yai> 9) yai=9;
}


if (random(4)==0)
{
	if (mi> 3) mi=3;
	if (yi> 2) yi=2;
	if (yai> 8) yai=8;
}
if (mi<2) mi=2;

        switch(items[3])
        {
        case "package":


                  switch( which )
                {
                case "besttz" :
 
                        buy_ob = new("/p/item/tz/ar18");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/p/item/tz/bt18");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/p/item/tz/hd18");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/p/item/tz/nk18");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/p/item/tz/sc18");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/p/item/tz/sd18");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/p/item/tz/wi18");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/p/item/tz/wt18");
                        buy_ob->move(ob, 1);


                        ob->add("hymoney",-value);
                        break;

                case "money" :
 
                        buy_ob = new("/clone/money/gold");
                        buy_ob->set_amount(5000);
                        buy_ob->move(ob, 1);
                        ob->add("hymoney",-value);
                        break;

                case "item1" :
file = read_file("/clone/medicine/wgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
            buy_ob = new(location);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

                case "item2" :
file = read_file("/clone/medicine/tzgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
            buy_ob = new(location);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;
                        
                case "weapon1" :

ayai=random(100);
ayai=ayai+random(381);
if (ayai>480) ayai=479;

buy_ob = new("/p/item/ritemw/W"+typew[random(9)]+ayai);
if (ob->query_temp("buyweaponlbw"))
buy_ob = new("/p/item/ritemw/W"+ob->query_temp("buyweaponlbw")+ayai);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 		ob->set_temp("buyweaponlbw",0);
		ob->set_temp("buyweaponlba",0);
                        ob->add("hymoney",-value);
                        break;

                case "weapon12" :

ayai=100+random(100);

buy_ob = new("/p/item/ritemw/W"+typew[random(9)]+ayai);
if (ob->query_temp("buyweaponlbw"))
buy_ob = new("/p/item/ritemw/W"+ob->query_temp("buyweaponlbw")+ayai);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
  		ob->set_temp("buyweaponlbw",0);
		ob->set_temp("buyweaponlba",0);
                        ob->add("hymoney",-value);
                        break;
                case "weapon13" :

ayai=200+random(100);

buy_ob = new("/p/item/ritemw/W"+typew[random(9)]+ayai);
if (ob->query_temp("buyweaponlbw"))
buy_ob = new("/p/item/ritemw/W"+ob->query_temp("buyweaponlbw")+ayai);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
  		ob->set_temp("buyweaponlbw",0);
		ob->set_temp("buyweaponlba",0);
                        ob->add("hymoney",-value);
                        break;

                case "weapon14" :
ayai=300+random(100);
buy_ob = new("/p/item/ritemw/W"+typew[random(9)]+ayai);
if (ob->query_temp("buyweaponlbw"))
buy_ob = new("/p/item/ritemw/W"+ob->query_temp("buyweaponlbw")+ayai);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
  		ob->set_temp("buyweaponlbw",0);
		ob->set_temp("buyweaponlba",0);
                        ob->add("hymoney",-value);
                        break;

                case "cloth1" :

ayai=random(100);
ayai=ayai+random(381);
if (ayai>480) ayai=479;

buy_ob = new("/p/item/ritema/A"+typea[random(10)]+ayai);
if (ob->query_temp("buyweaponlba"))
buy_ob = new("/p/item/ritema/A"+ob->query_temp("buyweaponlba")+ayai);

if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
  		ob->set_temp("buyweaponlbw",0);
		ob->set_temp("buyweaponlba",0);
                        ob->add("hymoney",-value);
                        break;

               case "cloth12" :

ayai=100+random(100);

buy_ob = new("/p/item/ritema/A"+typea[random(10)]+ayai);
if (ob->query_temp("buyweaponlba"))
buy_ob = new("/p/item/ritema/A"+ob->query_temp("buyweaponlba")+ayai);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
  		ob->set_temp("buyweaponlbw",0);
		ob->set_temp("buyweaponlba",0);
                        ob->add("hymoney",-value);
                        break;
               case "cloth13" :

ayai=200+random(100);

buy_ob = new("/p/item/ritema/A"+typea[random(10)]+ayai);
if (ob->query_temp("buyweaponlba"))
buy_ob = new("/p/item/ritema/A"+ob->query_temp("buyweaponlba")+ayai);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
  		ob->set_temp("buyweaponlbw",0);
		ob->set_temp("buyweaponlba",0);
                        ob->add("hymoney",-value);
                        break;           
               case "cloth14" :

ayai=300+random(100);

buy_ob = new("/p/item/ritema/A"+typea[random(10)]+ayai);
if (ob->query_temp("buyweaponlba"))
buy_ob = new("/p/item/ritema/A"+ob->query_temp("buyweaponlba")+ayai);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
  		ob->set_temp("buyweaponlbw",0);
		ob->set_temp("buyweaponlba",0);
                        ob->add("hymoney",-value);
                        break;

               case "tzweapon" :


buy_ob = new("/p/item/ritemtz3/W"+typew[random(9)]+random(89));
if (ob->query_temp("buyweaponlbw"))
buy_ob = new("/p/item/ritemtz3/W"+ob->query_temp("buyweaponlbw")+random(89));
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
  		ob->set_temp("buyweaponlbw",0);
		ob->set_temp("buyweaponlba",0);
                        ob->add("hymoney",-value);
                        break;

               case "tzcloth" :


buy_ob = new("/p/item/ritemtz3/A"+typea[random(10)]+random(89));	
if (ob->query_temp("buyweaponlba"))
buy_ob = new("/p/item/ritemtz3/A"+ob->query_temp("buyweaponlba")+random(89));
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
  		ob->set_temp("buyweaponlbw",0);
		ob->set_temp("buyweaponlba",0);
                        ob->add("hymoney",-value);
                        break;                        

               case "jyszhb" :
ob->set("jiuyin/full",1);
ob->set("szj/over200",1);
ob->set("szj/passed",1);
ob->set("double_attack",1);
buy_ob = new("/clone/book/shenzhao-jing");
            buy_ob->move(ob,1);
buy_ob = new("/clone/book/jiuyin-book");
            buy_ob->move(ob,1);                        


        tell_object(ob, HIM "�����˾���,����,������\n" NOR);
                        ob->add("hymoney",-value);
                        break;                        


               case "update23" :

lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);

if (ob->query_temp("buyuplb")) lb=ob->query_temp("buyuplb",1);
  		ob->set_temp("buyuplb",0);
lv=200;
lb=lb+lv;
buy_ob = new("/p/newweapon/weaponobj/jade"+lb);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "update24" :

lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);

if (ob->query_temp("buyuplb")) lb=ob->query_temp("buyuplb",1);
  		ob->set_temp("buyuplb",0);
lv=300;
lb=lb+lv;
buy_ob = new("/p/newweapon/weaponobj/jade"+lb);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "update25" :

lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);

if (ob->query_temp("buyuplb")) lb=ob->query_temp("buyuplb",1);
  		ob->set_temp("buyuplb",0);
lv=400;
lb=lb+lv;
buy_ob = new("/p/newweapon/weaponobj/jade"+lb);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;


               case "update26" :

lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);

if (ob->query_temp("buyuplb")) lb=ob->query_temp("buyuplb",1);
  		ob->set_temp("buyuplb",0);
lv=500;
lb=lb+lv;
buy_ob = new("/p/newweapon/weaponobj/jade"+lb);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;
               case "update27" :

lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);

if (ob->query_temp("buyuplb")) lb=ob->query_temp("buyuplb",1);
  		ob->set_temp("buyuplb",0);
lv=600;
lb=lb+lv;
buy_ob = new("/p/newweapon/weaponobj/jade"+lb);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "update28" :

lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);

if (ob->query_temp("buyuplb")) lb=ob->query_temp("buyuplb",1);
  		ob->set_temp("buyuplb",0);
lv=700;
lb=lb+lv;
buy_ob = new("/p/newweapon/weaponobj/jade"+lb);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "update29" :

lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);

if (ob->query_temp("buyuplb")) lb=ob->query_temp("buyuplb",1);
  		ob->set_temp("buyuplb",0);
lv=800;
lb=lb+lv;
buy_ob = new("/p/newweapon/weaponobj/jade"+lb);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

                case "ring1" :
ayai=random(60);
if (ayai>59) ayai=59;
if (random(2)==0 && ayai>=20) ayai=ayai-10;
if (random(3)==0 && ayai>=30) ayai=ayai-10;	
if (random(4)==0 && ayai>=40) ayai=ayai-10;	
if (random(5)==0 && ayai>=50) ayai=ayai-10;	
buy_ob = new("/clone/gem/ring"+ayai);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;


                case "ring2" :

ayai=random(60);
if (ayai>59) ayai=59;
if (random(2)==0 && ayai>=20) ayai=ayai-10;
if (random(3)==0 && ayai>=30) ayai=ayai-10;	
if (random(4)==0 && ayai>=40) ayai=ayai-10;	
if (random(5)==0 && ayai>=50) ayai=ayai-10;	
buy_ob = new("/p/item/tz/ring"+ayai);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;
                        
               case "weapon2" :

buy_ob = new("/p/newweapon/weaponobj/kuangshi"+mi);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;


               case "weapon23" :

buy_ob = new("/p/newweapon/weaponobj/kuangshi3");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;
               case "weapon24" :

buy_ob = new("/p/newweapon/weaponobj/kuangshi4");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;                        
               case "weapon25" :

buy_ob = new("/p/newweapon/weaponobj/kuangshi5");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;                        
               case "weapon26" :

buy_ob = new("/p/newweapon/weaponobj/kuangshi6");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;                        

               case "weapon27" :

buy_ob = new("/p/newweapon/weaponobj/kuangshi7");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;     
               case "weapon28" :

buy_ob = new("/p/newweapon/weaponobj/kuangshi8");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;                 


               case "weapon29" :

buy_ob = new("/p/newweapon/weaponobj/kuangshi9");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;                 


               case "weapon2A" :

buy_ob = new("/p/newweapon/weaponobj/kuangshi10");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;                 


               case "cloth2" :

buy_ob = new("/p/newweapon/weaponobj/buliao"+mi);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;


               case "cloth23" :

buy_ob = new("/p/newweapon/weaponobj/buliao3");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "cloth24" :

buy_ob = new("/p/newweapon/weaponobj/buliao4");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;
                        
               case "cloth25" :

buy_ob = new("/p/newweapon/weaponobj/buliao5");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "cloth26" :

buy_ob = new("/p/newweapon/weaponobj/buliao6");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "cloth27" :

buy_ob = new("/p/newweapon/weaponobj/buliao7");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "cloth28" :

buy_ob = new("/p/newweapon/weaponobj/buliao8");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;                        
                                                                        
               case "cloth29" :

buy_ob = new("/p/newweapon/weaponobj/buliao9");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;     
                        

               case "cloth2A" :

buy_ob = new("/p/newweapon/weaponobj/buliao10");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;                             


               case "yu2" :

buy_ob = new("/p/newweapon/weaponobj/material"+yi);
//if (random(2)==1) buy_ob = new("/p/newweapon/weaponobj/material"+yai);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;



               case "yu23" :

buy_ob = new("/p/newweapon/weaponobj/material3");
//if (random(2)==1) buy_ob = new("/p/newweapon/weaponobj/material9");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "yu24" :

buy_ob = new("/p/newweapon/weaponobj/material4");
//if (random(2)==1) buy_ob = new("/p/newweapon/weaponobj/material10");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "yu25" :

buy_ob = new("/p/newweapon/weaponobj/material5");
//if (random(2)==1) buy_ob = new("/p/newweapon/weaponobj/material11");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;


               case "yu26" :

buy_ob = new("/p/newweapon/weaponobj/material6");
//if (random(2)==1) buy_ob = new("/p/newweapon/weaponobj/material11");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;


               case "yu202" :

buy_ob = new("/p/newweapon/weaponobj/material"+yai);
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;



               case "yu232" :

buy_ob = new("/p/newweapon/weaponobj/material9");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "yu242" :

buy_ob = new("/p/newweapon/weaponobj/material10");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "yu252" :

buy_ob = new("/p/newweapon/weaponobj/material11");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;


               case "yu262" :

buy_ob = new("/p/newweapon/weaponobj/material12");
if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

               case "update2" :

lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);

if (ob->query_temp("buyuplb")) lb=ob->query_temp("buyuplb",1);
  		ob->set_temp("buyuplb",0);


if (random(4)==0) lv=100;
if (random(16)==0) lv=200;
if (random(32)==0) lv=300;
if (random(64)==0) lv=400;
if (random(128)==0) lv=500;	
if (random(256)==0) lv=600;
if (random(512)==0) lv=700;
if (random(1024)==0) lv=800;


if (random(2)==0 && lv >=300 ) lv= 300;
if (random(3)==0 && lv >=400 ) lv= 400;

if (random(2)==0)
{
	if (lv> 500) lv=500;
}

if (random(3)==0)
{
	if (lv> 600) lv=600;
}

if (random(4)==0)
{
	if (lv> 700) lv=700;
}

lb=lb+lv;

buy_ob = new("/p/newweapon/weaponobj/jade"+lb);

if ( buy_ob)
{
            buy_ob->move(ob,1);
        tell_object(ob, HIM "������һ" +  buy_ob->query("unit") +  buy_ob->name() +
                        HIM "��\n" NOR);
}
 
                        ob->add("hymoney",-value);
                        break;

                case "yj-rune" :
                        for (i = 0; i < 7; i++)
                        {
//                                buy_ob = new("/clone/enchase/rune31");
//                                buy_ob->move(ob, 1);
//                                buy_ob = new("/clone/enchase/rune33");
//                                buy_ob->move(ob, 1);
//                        ob->add("hymoney",-value);
                        }
                        break;
                default :
                        break;
                }

                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                return 1;

        case "object":

                buy_ob = new(items[2]);
                if (! objectp(buy_ob))
                {
                        write("������Ʒʧ�ܣ����뱾վADMIN��ϵ��\n");
                        return 0;
                }


                buy_ob->move(ob, 1);
                ob->add("hymoney",-value);
                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                return 1;

      
        case "gold" :

                ob->add("balance", items[2]);


                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                ob->add("hymoney",-value);
                return 1;


        
     
                
        default:
                write("��Ч��Ʒ���࣡\n");
                return 0;
        }
}





int ask_newbie2()
{
    string week, month, year, day, time,hydata;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
 	 object target;
 	 	object me = this_player();
target=this_object();
if(me->is_busy())
{
write("�Բ�������æ����һ�������� ��\n");
                return 1;	
}

if(me->query_temp("nanxianok"))
{
write("�Բ�����һ�����ߣ���ֻ�ܰ���һ�Ρ� ��\n");
                return 1;	
}

if (me->query("combat_exp") > 1000000)
{
write("�Բ���ֻ�г������ֵ����֣��Ҳ���΢��һ�� ��\n");
                return 1;	
}
if (me->query("zhuanshen"))
        {
write("�Բ���ֻ�г������ֵ����֣���ת����ң��Ҳ���΢��һ�� ����\n");
                return 1;	
        }
 message_vision(HIY "\nֻ��$N" HIY "ĬĬ��ת��ָ��Ѩ "+
                     HIY "����������һ������ͷ������ð��������Ȼʩչ��\n"
                     "һ��ָ�����Դ���ָ��˲ʱ�����$n" HIY "ȫ����ʮ��\n"
                     "����Ѩ������һ�ᣬ�����$n" HIY "���ۡ���һ���³�\n"
                     "������Ѫ����ɫ��ʱ�����������쳣, ������档\n" NOR, target, me);

         if (me->query("qi") <= 888)
                me->set("qi", 888);
         if (me->query("eff_qi") <= 888)
                me->set("eff_qi", 888);
         if (me->query("jing") <= 888)
                me->set("jing", 888);
         if (me->query("eff_jing") <= 888)
               me->set("eff_jing", 888);
me->set_temp("nanxianok",1);
me->start_busy(8);

        return 1;
}

int ask_pk()
{
    string week, month, year, day, time,hydata;
    string check,mt;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
 	 object target;
 	 	object me = this_player();
target=this_object();
sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);

if(me->is_busy())
{
write("�Բ�������æ����һ�������� ��\n");
                return 1;	
}

if(me->query_temp("nanxianok"))
{
write("�Բ�����һ�����ߣ���ֻ�ܰ���һ�Ρ� ��\n");
                return 1;	
}

if (me->query("combat_exp",1) < 3000000)
{
write("�Բ�����ľ���̫С���ˣ�ȥ��ս������ ��\n");
                return 1;	
}

if (me->query("combat_exp",1) > 60000000)
{
write("�Բ����������̫ǿ�ˣ���help boss ��ս��İ� ��\n");
                return 1;	
}

if (me->query_condition("pkjob"))
{
write("�Բ��������ս��������һ�������� ��\n");
                return 1;	
}

hydata=year+month+day;
//write(hydata);

    if ( me->query("pkdata")==hydata && me->query("pktime",1)>3)
{
command("say ÿ����ÿ��ֻ��������ս����!");
        return 1;
}

if ( me->query("pkdata")!=hydata)
{
me->set("pktime",1);	
}
command("say �õģ���ս��ʼ!");

if (me->query("combat_exp",1) >= 3000000) mt="/p/migong/boss/e1";
if (me->query("combat_exp",1) >= 5000000) mt="/p/migong/boss/e2";
if (me->query("combat_exp",1) >= 10000000) mt="/p/migong/boss/e3";
if (me->query("combat_exp",1) >= 15000000) mt="/p/migong/boss/e4";
if (me->query("combat_exp",1) >= 20000000) mt="/p/migong/boss/e5";
if (me->query("combat_exp",1) >= 25000000) mt="/p/migong/boss/e6";
if (me->query("combat_exp",1) >= 30000000) mt="/p/migong/boss/e7";
if (me->query("combat_exp",1) >= 35000000) mt="/p/migong/boss/e8";
if (me->query("combat_exp",1) >= 40000000) mt="/p/migong/boss/e9";
if (me->query("combat_exp",1) >= 45000000) mt="/p/migong/boss/e10";
if (me->query("combat_exp",1) >= 50000000) mt="/p/migong/boss/e11";
if (me->query("combat_exp",1) >= 55000000) mt="/p/migong/boss/e12";

me->move(mt);
me->apply_condition("pkjob",50);
me->set("pkdata",hydata);
if (me->query("pktime",1) >3 || !me->query("pktime",1)) 
{
me->set("pktime",1);
}
else
{
me->add("pktime",1);
}
me->start_busy(2);

        return 1;
}


int do_answer(string arg)
{
        object money;
        object ob;
        object me;
        object ganjiang;
mapping type;
        me = this_player();
//        if (me->query_temp("item/status") != "answer_type")
//                return 0;
	
        if (! arg)
                return notify_fail("��Ҫ��ʲôָ�������������\n");

        if (! me->query_temp("paid/nanxian", 1))
                return notify_fail("ָ������װ������Ҫ��ǧ���ƽ�\n");


	if( undefinedp(valid_typesw[arg]) && undefinedp(valid_typesa[arg]))
		return notify_fail("û����������������\n");

if(valid_typesw[arg])        me->set_temp("buyweaponlbw",arg);
if(valid_typesa[arg])        me->set_temp("buyweaponlba",arg);
		me->delete_temp("paid/nanxian");
		me->set_temp("paid/nanxian",0);
		return notify_fail("֪���ˣ���Ҫ����"+arg+"�ɡ�\n");

		
}        

int accept_object(object me, object ob)
{
        string status;
	int    val,val2;

        status = query_temp("item/status");
		val =  8000;
                val *= 10000;

                if (! ob->query("money_id"))
                {
                        command("say ָ�����������Ҫ��ǧ���ƽ�");
                        return 0;
                }
        if (ob->value() < val)
        {
                command("say Ǯ��������ָ�����������Ҫ��ǧ���ƽ�");
                return 0;
        }
if  (ob->value() >= val2)
{   
		message_vision("$N��$n˵���������Ҫʲô�������������(answer ����)��\n"
		"���� ��(sword) ��(blade) ��(hammer) ��(whip) ��(club) \n"
		"���� ��(staff)  ����(throwing)  ذ��(dagger) ��(axe)\n"
		"���� ����(hands) ��װ(cloth) ����(armor) ѥ��(boots) ͷ��(head)��\n"
		"���� ����(neck)�Ǵ�(surcoat)����(shield) ����(waist) ����(wrists)��\n",
                               this_object(), me);

                me->set_temp("paid/nanxian", 1);
return 1;
}        
                
     return 0;           	
}	



string ask_liwu15()
{
  string msg;
  object ob1;
  object me=this_player();
  int exp_bound,qn_bound,neili;
  me->set_temp("nbjob19",1);
  return me->query("name")+"��ס���������������";
}    