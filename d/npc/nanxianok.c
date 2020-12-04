// This program is a part of NITAN MudLIB

#include <ansi.h>

inherit NPC;

int ask_hygoods();
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
        "tishenwawa"  : "��������:2:/clone/misc/cloth:object:�������޿���Ϊ�㵵��һ��",
        "tongren"  : "��Ѩͭ��:100:/clone/misc/cloth:object:��Ѩͭ�˳�Ѩʱ����������",
        "seasoncard"            : "���Ȼ�Ա:60:seasoncard:card:��Ա���� ������Ա����",
        "yearcard"              : "��Ȼ�Ա:300:yearcard:card:��Ա�꿨 ����10����������",
        "forevercard"           : "�����Ա:500:forevercard:card:��Ա���� ���ͳ�Ѩͭ��",
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

        write(HIG "�����������" HIR "��" HIG "��ǵķ����Ϊ�������\n" NOR);
        write(HIG "�����������" HIY "��" HIG "��ǵķ����Ϊ�����Ա���ޡ�\n" NOR);
        write(HIG "�������Ķ��й�˵��������ǰ�뿼������� ���޲��ˡ���˻���\n" NOR);
        write(HIG "-------------------------------------------------------------------------------\n\n" NOR);
}


void create()
{
        set_name("����", ({ "nan xian", "nan", "xian" }));
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
                "��Ա��Ʒ": (: ask_hygoods :),
                "membergoods": (: ask_hygoods :),	
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



public int buy_goods(string which)
{
        mixed * all, items;
        mixed specials;
        string strtmp;
        int i, vip, value, money;
        object buy_ob;
object ob=this_player();
        if (!ob->query("hyvip"))
        {
                write("�Բ���ֻ�л�Ա�������ܴ˷�����μ� " HIR "help member " NOR " ��\n");
                return 1;
        }


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
/*
        if (vip == 3)
                value = value * 80 / 100;
        else
        if (vip == 2)
                value = value * 85 / 100;
        else
        if (vip == 1)
                value = value * 90 / 100;
*/
        if (value < 1) value = 1;

        if (money < value)
        {
                write("�Բ������ĺ���������������\n");
                return 1;
        }

        switch(items[3])
        {
        case "package":


                switch( which )
                {
                case "newbie" :
                        buy_ob = new("/clone/gift/xuanhuang");
                        buy_ob->set_amount(10);
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/jiuzhuan");
                        buy_ob->set_amount(10);
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/tianxiang");
                        buy_ob->set_amount(20);
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/puti-zi");
                        buy_ob->set_amount(50);
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/xiandan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/xiandan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/xisuidan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/xisuidan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/shenliwan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/shenliwan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/unknowdan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/gift/unknowdan");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/medicine/yuqing");
                        buy_ob->set_amount(600);
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/max/zhenyu");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/max/longjia");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/max/xuanhuang");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/int3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/int3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/str3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/str3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/con3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/con3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/dex3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/fam/gift/dex3");
                        buy_ob->move(ob, 1);
                        buy_ob = new("/clone/item/tianjing");
                        buy_ob->move(ob, 1);
                        ob->add("balance", "1000000000");
                        //MEMBER_D->db_fee_member(ob, 31);
                        break;


                case "yj-rune" :
                        for (i = 0; i < 7; i++)
                        {
                                buy_ob = new("/clone/enchase/rune31");
                                buy_ob->move(ob, 1);
                                buy_ob = new("/clone/enchase/rune33");
                                buy_ob->move(ob, 1);
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
                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                return 1;

        case "objamount":
                buy_ob = new(items[2]);
                if (! objectp(buy_ob))
                {
                        write("������Ʒʧ�ܣ����뱾վADMIN��ϵ��\n");
                        return 0;
                }

                if (which == "putizi")
                        buy_ob->set_amount(20);
                else
                if (which == "jiuzhuan")
                        buy_ob->set_amount(10);
                else
                if (which == "yuqingsan")
                        buy_ob->set_amount(120);
                else
                if (which == "tianxiang")
                        buy_ob->set_amount(15);
                else
                if (which == "xuanhuang1")
                        buy_ob->set_amount(5);

                buy_ob->move(ob, 1);

                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                return 1;

        case "card":

                if (which != "monthcard" && which != "seasoncard" &&
                    which != "yearcard"  && which != "forevercard")
                {
                        write("û���������͵Ļ�Ա����\n");
                        return 0;
                }

                if (which == "monthcard")
ob->add("hyday",31);
                else
                if (which == "seasoncard")
ob->add("hyday",92);
                else
                if (which == "yearcard")
ob->add("hyday",365);
                else
                if (which == "forevercard")
ob->add("hyday",1800000);


                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                return 1;

        case "story":
                // ���ȼ���Ƿ��й�����
                if (ob->query("gift/" + which))
                {
                        write("���Ѿ��й��ù����ˣ�\n");
                        return 0;
                }
                ob->add("gift/" + which, 1);
                ob->add(items[2], 1);

                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                return 1;

        case "gold" :

                ob->add("balance", items[2]);


                write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                return 1;

        case "special":
                // ���ȼ���Ƿ��и�special
                // ͬʱ����ܹ���special���ܴ���7
                if (! ob->query("special_skill"))specials = 0;
                else specials = keys(ob->query("special_skill"));
                if (1) // ��������
                {
                        if (sizeof(specials) > 0)
                        {
                                if (member_array(which, specials) != -1)
                                {
                                        write("�Բ������Ѿ���������⼼���ˣ�\n");
                                        return 0;
                                }
                                if (sizeof(specials) >= 24)
                                {
                                        write("�Բ���һ���ʺ����ֻ��ӵ���ĸ����⼼�ܣ�\n");
                                        return 0;
                                }
                        }


                        ob->set("special_skill/" + which, 1);
                        write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                        return 1;
                }
                else
                {
                        write("��ʱֹͣ�������⼼�ܣ����½⣡\n");
                        return 0;
                }
        
        case "special2":
                if (! ob->query("special_skill")) specials = 0;
                else specials = keys(ob->query("special_skill"));
                if (ob->query("reborn/times")) // ��������
                {
                        if (sizeof(specials) > 0)
                        {
                                if (member_array(which, specials) != -1)
                                {
                                        write("�Բ������Ѿ������ת�������ˣ�\n");
                                        return 0;
                                }
                        }

                        ob->set("special_skill/" + which, 1);
                        write(HIC "���ܹ������� " HIY + value + HIC + " $HY, ף�����ˣ�\n" NOR);
                        return 1;
                }
                else
                {
                        write("���޷�����ת�����ܣ����½⣡\n");
                        return 0;
                }
                
        default:
                write("��Ч��Ʒ���࣡\n");
                return 0;
        }
}