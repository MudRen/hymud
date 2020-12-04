// This program is a part of NT MudLIB

#include <ansi.h>

inherit ROOM;

#define PROCEDURE_FUND  0.01            // 1/100 ��������
#define STOCK_VALUE     10000           // һ�Ź�Ʊ��ֵ

varargs string stockvalue_change_description(float change, string type)
{
        string bgcolor;

        switch(type)
        {
                case "t3g2":
                        bgcolor = BGRN;
                        break;

                case "t3r2":
                        bgcolor = BRED;
                        break;
                default:
                        bgcolor = "";
                        break;
        }

        change = to_float(change);

        if( change > 0 )
                return bgcolor+sprintf(HIR"��%5.2f", change);

        else if( change < 0 )
                return bgcolor+sprintf(HIG"��%5.2f", -change);
        else
                return bgcolor+sprintf(HIW"  %5.2f", change);
}


int do_liststock(string arg)
{
        int count;
        mapping stocks = STOCK_D->query_stocks();
        string *stock_sort = sort_array(keys(stocks), 1);
        mapping data;
        int min, max;
        string *msg = allocate(0);
        //float percent = PROCEDURE_FUND - me->query_skill("stock", 1)/10000.;
        float percent = 0.01;
        object me = this_player();

        if( arg )
        {
                if( sscanf(arg, "%d %d", min, max) != 2 )
                        sscanf(arg, "%d", min);
        }

        msg = ({"����    ��Ʊ����     �ּ�    �ǵ�  �ǵ����� ���̼� ��߼� ��ͼ� �ɽ����� \n"});
        msg += ({"������������������������������������������������������������������������������������������\n"});

        foreach(string stock in stock_sort)
        {
                count++;

                if( max )
                {
                        if( to_int(stock) < min || to_int(stock) > max ) continue;
                }
                else
                {
                        if( min && to_int(stock) != min ) continue;
                }

                data = stocks[stock];

                if( !data["��Ʊ����"] ) continue;

                msg += ({sprintf(HIM"%-6s"HIW"  %-8s "HIY"%8.2f"NOR" %-8s %7.2f%% "NOR WHT"%6.2f "HIB"%6.2f %6.2f  "NOR BYEL HIY"%d\n"NOR,
                        stock,
                        data["��Ʊ����"],
                        data["�ּ�"],
                        stockvalue_change_description(data["�ǵ�"], data["״̬"]),
                        data["�ǵ���"],
                        data["����"],
                        data["���"],
                        data["���"],
                        data["�ɽ�����"],
                )});
        }
        msg += ({"������������������������������������������������������������������������������������������\n"});
        msg += ({MAG"�� "HIM+count+NOR MAG" ֻ���й�Ʊ��"YEL"��Ʊ��λΪ "HIY"1"NOR YEL" ���ƽ�/�ţ�"NOR RED"����������Ϊ "HIR+sprintf("%.2f%%", percent*100.)+NOR RED"��\n"NOR});
        msg += ({HIC"��Ʊ�����������Ի���A�ɣ�10���Ӹ���һ�Σ����θ���ʱ�䣺"+sprintf("%s\n", TIME_D->replace_ctime(STOCK_D->query_last_update_time()))+NOR});
        me->start_more(implode(msg, ""));
        return 1;

}

void confirm_buystock(object me, string num, int totalcost, int new_amount, float new_value, float cur_value, int amount, string stock_name, string arg)
{
        int td;

        if( !arg )
                return me->finish_input();

        arg = lower_case(arg);

        if( arg != "y" && arg != "yes" )
        {
                tell_object(me, "ȡ�������Ʊ��\n");
                return me->finish_input();
        }

        if( me->query("balance")<totalcost )
        {
                tell_object(me, "�������е�Ǯ���㡣\n");
                return me->finish_input();
        }

        if( STOCK_D->query_get_stock_flag() )
        {
                tell_object(me, "��Ʊ���ϸ����У����Ժ��ٽ��н��ס�\n");
                return me->finish_input();
        }

        td = time() / 86400;


        me->set("stock/"+num+"/amount", new_amount);
        me->set("stock/"+num+"/value", new_value);

        if( me->query("stock/"+num+"/limit/which_day") != td )
        {
                me->set("stock/"+num+"/limit/amount", amount);
                me->set("stock/"+num+"/limit/which_day", td);
        }
        else
        {
                me->addn("stock/"+num+"/limit/amount", amount );
        }

        CHANNEL_D->channel_broadcast("stock", me->query_idname()+RED"�� "HIY+sprintf("%.2f", cur_value)+NOR RED" �ɼ۹��롸"HIW+stock_name+NOR RED"����Ʊ "+amount+" �š�"NOR);
        tell_object(me, "������ɡ�\n");
        me->finish_input();

        me->addn("balance", -totalcost);
        //TOP_D->update_top_rich(me);
        me->save();
}

int do_buystock(string arg)
{

        mapping stocks = STOCK_D->query_stocks();
        string num;
        int amount;
        float old_value;
        float new_value;
        float cur_value;

        int old_amount;
        int new_amount;
        int cost;
        int cost_extra;
        int *nowtime = TIME_D->query_realtime_array();
        float percent;
        object me = this_player();

        //tell_object(me, "��ƱϵͳĿǰ�޷��������¹��ơ���Ȩ����Ϣ�����⣬�����Ը���\n");

        if( !wizardp(me) && (/*nowtime[2] < 1 || nowtime[2] > 6 ||*/ nowtime[1] < 9 || nowtime[1] >= 22) )
        {
                tell_object(me, "��һ�����յ����Ͼŵ�������ʮ�������ס�\n");
                return 1;
        }

        if( STOCK_D->query_last_update_time() < time() - 48*60*60 )
        {
                tell_object(me, "��Ʊ������δ���£��޷����н��ס�\n");
                return 1;
        }

        if( STOCK_D->query_get_stock_flag() )
        {
                tell_object(me, "��Ʊ���ϸ����У����Ժ��ٽ��н��ס�\n");
                return 1;
        }

        if( !arg || sscanf(arg, "%s %d", num, amount) != 2 )
        {
                tell_object(me, "��������ȷ�ĸ�ʽ������buy 000002 100��\n");

                return 1;
        }

        if( amount < 1 )
        {
                tell_object(me, "�����ٱ��빺��һ�Ź�Ʊ��\n");
                return 1;
        }

        if( !mapp(stocks[num]) || !stocks[num]["��Ʊ����"] )
        {
                tell_object(me, "û�� "+num+" ��һֻ��Ʊ��\n");
                return 1;
        }

        if( stocks[num]["״̬"] == "t3r2" )
        {
                tell_object(me, "�⵵��Ʊ�Ѿ���ͣ���޷������ˡ�\n");
                return 1;
        }

        old_amount=me->query("stock/"+num+"/amount");
        new_amount = amount + old_amount;


        if( new_amount > 10000000 )
        {
                tell_object(me, "ÿֻ��Ʊ���ֻ�ܹ��� 10,000,000 �š�\n");
                return 1;
        }


        old_value=to_float(me->query("stock/"+num+"/value"));
        cur_value = stocks[num]["�ּ�"];
        new_value = (old_value * old_amount + cur_value * amount) / (amount + old_amount);

        //percent = PROCEDURE_FUND - me->query_skill("stock", 1)/10000.;
        percent = 0.01;

        cost = to_int(to_int(cur_value*100) * STOCK_VALUE * amount / 100);
        cost_extra = to_int(cost * percent);

        if( cost + cost_extra < 1 )
        {
                tell_object(me, "���ϼ��������֪ͨ��ʦ����\n");
                return 1;
        }

        tell_object(me,
                WHT"��Ʊ����      "NOR HIW+num+" "+stocks[num]["��Ʊ����"]+NOR"\n"
                "��������������������������������������\n"
                YEL"��Ʊ���ڼ۸�  "HIY+sprintf("%.2f", cur_value)+"\n"NOR
                GRN"������Ʊ����  "HIG+amount+"\n"NOR
                GRN"Ŀǰ�ֹɼ۸�  "HIG+sprintf("%.2f", old_value)+"\n"NOR
                GRN"Ŀǰ�ֹ�����  "HIG+old_amount+"\n"NOR
                CYN"ƽ��֮��۸�  "HIC+sprintf("%.2f", new_value)+"\n"NOR
                CYN"������Ʊ��ֵ  "HIC+cost+"\n"NOR
                CYN"������������  "HIC+cost_extra+HIR"("+sprintf("%.2f", percent*100.)+"%)\n"NOR
                CYN"�����ܹ�����  "HIC+(cost + cost_extra)+"\n"NOR
                "��������������������������������������\n"
                HIY"�Ƿ�ȷ�������Ʊ?"NOR YEL"(Yes/No)"NOR
        );


        input_to((: confirm_buystock, me, num, cost + cost_extra, new_amount, new_value, cur_value, amount, num+" "+stocks[num]["��Ʊ����"] :));
        return 1;
}

void confirm_sellstock(object me, string num, int totalearn, int new_amount, float old_value, float cur_value, int amount, string stock_name, string arg)
{

        if( !arg )
                return me->finish_input();

        arg = lower_case(arg);

        if( arg != "y" && arg != "yes" )
        {
                tell_object(me, "ȡ��������Ʊ��\n");
                return me->finish_input();
        }

        if( STOCK_D->query_get_stock_flag() )
        {
                tell_object(me, "��Ʊ���ϸ����У����Ժ��ٽ��н��ס�\n");
                return me->finish_input();
        }

        if( new_amount <= 0 )
                me->delete("stock/"+num);
        else
                me->set("stock/"+num+"/amount", new_amount);

        if( cur_value == old_value )
                CHANNEL_D->channel_broadcast("stock",

                        me->query_idname()+RED"�� "HIY+sprintf("%.2f", cur_value)+NOR RED" �ɼ��۳���"HIW+stock_name+NOR RED"����Ʊ "+amount+" �š�"NOR);
        else if( cur_value > old_value )
                CHANNEL_D->channel_broadcast("stock",
                        me->query_idname()+RED"�� "HIY+sprintf("%.2f", cur_value)+NOR RED" �ɼ��۳���"HIW+stock_name+NOR RED"����Ʊ "+amount+" �ţ����� "
                        HIY+to_int(to_int((cur_value-old_value)*100)*STOCK_VALUE/100*amount)+NOR RED"��" NOR);
        else
                CHANNEL_D->channel_broadcast("stock",
                        me->query_idname()+RED"�� "HIY+sprintf("%.2f", cur_value)+NOR RED" �ɼ��۳���"HIW+stock_name+NOR RED"����Ʊ "+amount+" �ţ����� "
                        HIY+to_int(to_int((old_value-cur_value)*100)*STOCK_VALUE/100*amount)+NOR RED"��" NOR);
        tell_object(me, "������ɡ�\n");

        me->finish_input();

        me->addn("balance", totalearn);
        //TOP_D->update_top_rich(me);
        me->save();
}

int do_sellstock(string arg)
{
        mapping stocks = STOCK_D->query_stocks();
        string num;
        int amount;
        int old_amount;
        int new_amount;
        float cur_value;
        float old_value;
        int earn, td, limit = 0;
        int *nowtime = TIME_D->query_realtime_array();
        object me = this_player();


        if( !wizardp(me) && (/*nowtime[2] < 1 || nowtime[2] > 6 ||*/ nowtime[1] < 9 || nowtime[1] >= 22) )
        {
                tell_object(me, "��һ�����յ����Ͼŵ�������ʮ�������ס�\n");
                return 1;
        }

        if( STOCK_D->query_last_update_time() < time() - 48*60*60 )
        {
                tell_object(me, "��Ʊ������δ���£��޷����н��ס�\n");
                return 1;
        }

        if( STOCK_D->query_get_stock_flag() )
        {
                tell_object(me, "��Ʊ���ϸ����У����Ժ��ٽ��н��ס�\n");
                return 1;
        }

        if( !arg || sscanf(arg, "%s %d", num, amount) != 2 )
        {
                tell_object(me, "��������ȷ�ĸ�ʽ������sell 000002 100��\n");
                return 1;
        }

        if( amount < 1 )
        {
                tell_object(me, "�����ٱ������һ�Ź�Ʊ��\n");
                return 1;
        }

        if( !mapp(stocks[num]) || !stocks[num]["��Ʊ����"] )

        {
                tell_object(me, "û�� "+num+" ��һֻ��Ʊ��\n");
                return 1;
        }

        if( stocks[num]["״̬"] == "t3g2" )
        {
                tell_object(me, "�⵵��Ʊ�Ѿ���ͣ���޷������ˡ�\n");
                return 1;
        }

        td = time() / 3600;

        old_amount=me->query("stock/"+num+"/amount");

        // ���칺��Ĺ�Ʊ����������
        if( me->query("stock/"+num+"/limit/which_day") == td )
                limit=me->query("stock/"+num+"/limit/amount");

        new_amount = old_amount - amount;

        old_value=to_float(me->query("stock/"+num+"/value"));
        cur_value = stocks[num]["�ּ�"];

        if( old_amount < 1 )
        {
                tell_object(me, "�����ϲ�û�� "+num+" ��ֻ��Ʊ��\n");
                return 1;
        }

        if( new_amount < limit )

        {
                tell_object(me, "��ֻ��Ʊ������ֻ�� "+old_amount+" �ţ��ɽ��� "+(old_amount-limit)+" �š�\n");
                return 1;
        }

        earn = to_int(to_int(cur_value*100) * amount * STOCK_VALUE / 100);

        if( earn < 1 )
        {
                tell_object(me, "���ϼ��������֪ͨ��ʦ����\n");
                return 1;
        }

        tell_object(me,
                WHT"��Ʊ����      "NOR HIW+num+" "+stocks[num]["��Ʊ����"]+NOR"\n"
                "��������������������������������������\n"
                YEL"��Ʊ���ڼ۸�  "HIY+sprintf("%.2f", cur_value)+"\n"NOR
                GRN"Ŀǰ�ֹɼ۸�  "HIG+sprintf("%.2f", old_value)+"\n"NOR
                GRN"Ŀǰ�ֹ�����  "HIG+sprintf("%.2f%%", (cur_value - old_value) * 100. / old_value)+"\n"NOR
                GRN"���۹�Ʊ����  "HIG+amount+"\n"NOR
                CYN"�۳��ܹ����  "HIC+earn+"\n"NOR
                "��������������������������������������\n"
                HIY"�Ƿ�ȷ���۳���Ʊ?"NOR YEL"(Yes/No)"NOR
        );

        input_to((: confirm_sellstock, me, num, earn, new_amount, old_value, cur_value, amount, num+" "+stocks[num]["��Ʊ����"] :));
        return 1;
}

void create()
{

        set("short", "֤ȯ������");
        set("long", @LONG
����һ��֤ȯ��������ǽ�Ϲ���һ������(paizi)��
LONG );

        set("item_desc", ([
                "paizi" : @HELP
��ʾ������Ѷ
liststock              �г����л���A���г�����
liststock 000002       �г�����000002��Ʊ������

HELP,
        ]));
        set("exits", ([
                "south": "/d/city/wumiao",
        ]));
        set("no_fight", 1);
        set("coor/x", 20);
        set("coor/y", 0);
        set("coor/z", 0);
        setup();
}

void init()
{
        add_action("do_liststock", "liststock");
        //add_action("do_buystock", "buystock");
        //add_action("do_sellstock", "sellstock");

}
 
