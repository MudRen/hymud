
// blacksmith.c ����ʦ��
#include <ansi.h>
inherit NPC;

int check_money(object me, int amount);
void pay_him( object me, int amount);

void create()
{
            set_name("����", ({ "blacksmith" }) );
            set("long","�����õġ������ĵ��������ˡ���ô�;����������ɡ�\n");

                set("age", 14);
                set("attitude", "friendly");

                set("max_gin", 2000);
                set("max_kee", 3000);
                set("max_sen", 1000);

                set("str", 110);
                set("cor", 40);
                set("spi", 40);
                set("int", 60);

        set("force",800);
        set("max_force",800);

                set("combat_exp", 1000);
          
                setup();
                carry_object("/clone/misc/cloth");
                       
}
void init()
{       
                object me;
                me=this_player();
if(interactive(me)&&!this_object()->is_fighting())      
                call_out("greeting",1,me);
                add_action("do_repair","repair");
}

void greeting(object me)
{
                command("say �����������������Һ��ˣ���׼�޵ľ����µ�һ��������");
                command("say ������úܱ��˵�Ӵ(repair)������������");
}

int do_repair(string arg)
{
        int item_value,now_damage,cost,remain_money,lost_prop;
                object me,item;
                me=this_player();
if(!arg)
                return notify_fail("����Ҫ����ʲô����\n");
                item=present(arg,me);
if(!item)
                return notify_fail("��û��������������\n");
if(item->type()!="weapon")
                return notify_fail("�Բ��𡣡�����ֻ����ҵ��ϱ���---����������\n");
                now_damage=item->query("weapon_prop/damage");
                lost_prop=item->query("lost_prop");
if(lost_prop<=0)
                return notify_fail("���"+item->name()+"�úõģ���ʲô�ް���\n");
                item_value=item->query("value");
if(item_value<=100)
                return notify_fail("�ⶫ����ֵǮ���Ҳ���.\n");                 

                cost=item_value/(lost_prop+now_damage)*lost_prop*3/4;

                write("������÷�����"+cost+" coin\n",me);

if((remain_money=check_money(me,cost))<=0)

                return notify_fail("��û����ô��Ǯ");

else    
                pay_him(me,remain_money);

                item->unequip();
                item->set("weapon_prop/damage",lost_prop+now_damage);
                item->delete("lost_prop");
            return 1;                   
}


void pay_him(object who, int amount)

{
        object ob;
        object cash, tencash, gold, silver, coin;
        tencash = present("tenthousand-cash_money", who);
        cash = present("thousand-cash_money", who);
        gold = present("gold_money",who);
        silver = present("silver_money",who);
        coin = present("coin_money",who);
        if(tencash) destruct(tencash);
        if(cash) destruct(cash);
        if(gold) destruct(gold);
        if(silver) destruct(silver);
        if(coin) destruct(coin);


        if( amount < 1 ) amount = 1;
        if( amount/100000 ) {
                ob = new("/obj/money/thousand-cash");
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}

int check_money(object me, int amount)
{
        int remain,total;
        object cash, tencash, gold, silver, coin;

        tencash = present("tenthousand-cash_money", me);
        cash = present("thousand-cash_money", me);
        gold = present("gold_money",me);
        silver = present("silver_money",me);
        coin = present("coin_money",me);

        total = 0;
        if( tencash) total += tencash->value();
        if( cash) total += cash->value();
        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        if( total < amount ) return 0;

        return total-amount;
}


