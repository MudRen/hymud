// hp cmds (Mon  09-04-95)
// Update by Doing
// Update by Lonely

#include <ansi.h>
inherit F_CLEAN_UP;

string status_color(int current, int max);
 
int main(object me, string arg)
{
        object ob;
        mapping my;
        string sp;
        int craze;
 string temp1,temp2;
 int i,i1;
        seteuid(getuid(me));
if (me->query_temp("nbjob2",1) < 3 || !me->query_temp("nbjob2")) me->add_temp("nbjob2",1);
if (me->query_temp("nbjob2",1)>3) me->set_temp("nbjob2",3);

        if (arg && (arg == "-m"
           || sscanf(arg, "-m %s", arg)
           || sscanf(arg, "%s -m", arg)))
        {
                int ml, mn;
                mixed need;
                string combat_exp;
                int lv, level, exp;

                if (arg == "-m")
                        ob = me;
                else
                if (wizardp(me) || me->query("couple/couple_id"))
                {
                        ob = present(arg, environment(me));

                        if (! ob || ! ob->is_character())
                                ob = find_player(arg);

                        if (! ob || ! ob->is_character())
                                ob = find_living(arg);

                        if (! ob || ! ob->is_character() || ! me->visible(ob)) 
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                        if (! wizardp(me) && me->query("couple/couple_id") != ob->query("id"))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                } else
                        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

                my = ob->query_entire_dbase();

//                if (userp(ob) && (! stringp(my["born"]) || ! my["born"]))
//                        return notify_fail("��û�г����ţ��쿴ʲô��\n");

                if (my["max_jing"] < 1 || my["max_qi"] < 1)
                        return notify_fail("�޷��쿴" + ob->name(1) + "��״̬��\n");




                exp = ob->query("combat_exp") / 100;
                level = to_int(pow(to_float(exp), 1.0 / 3)) * 10 + 1;

                lv = ob->query("level");
                if (lv < 1) lv = 1;
                need = (lv + 1) * (lv + 1) * (lv + 1) * 10000 - ob->query("combat_exp");
                
                if (need < 1) need = 1;

 
                return 1;
        }

        if (arg && (arg == "-g"
           || sscanf(arg, "-g %s", arg)
           || sscanf(arg, "%s -g", arg)))
        {
                if (arg == "-g")
                        ob = me;
                else
                if (wizardp(me) || me->query("couple/couple_id"))
                {
                        ob = present(arg, environment(me));

                        if (! ob || ! ob->is_character())
                                ob = find_player(arg);

                        if (! ob || ! ob->is_character())
                                ob = find_living(arg);

                        if (! ob || ! ob->is_character() || ! me->visible(ob)) 
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");

                        if (! wizardp(me) && me->query("couple/couple_id") != ob->query("id"))
                                return notify_fail("��Ҫ�쿴˭��״̬��\n");
                } else
                        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

                my = ob->query_entire_dbase();

//                if (userp(ob) && (! stringp(my["born"]) || ! my["born"]))
//                        return notify_fail("��û�г����ţ��쿴ʲô��\n");

                if (my["max_jing"] < 1 || my["max_qi"] < 1)
                        return notify_fail("�޷��쿴" + ob->name(1) + "��״̬��\n");

                sp = (ob == me ? "��" : ob->name()) + "Ŀǰ���츳�������£�\n";
                sp += HIC "��" HIY "����������������������������������������������"
                      "����������������" HIC "��\n" NOR;
                sp += HIY "�� �� �� �� " HIC "�����ڡ� �����졻\n" NOR;
                sp += HIC "��" HIY "����������������������������������������������"
                      "����������������" HIC "��\n" NOR;

                sp += sprintf(HIW "�� �� �� �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]    \n",
                ob->query_str(),
                ob->query("str")
);

                sp += sprintf(HIW "�� �� �� �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]    \n",
                ob->query_int(),
                ob->query("int")
);

                sp += sprintf(HIW "�� �� �� �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]   \n",
                ob->query_con(),
                ob->query("con")
);

                sp += sprintf(HIW "�� �� �� �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]   \n",
                ob->query_dex(),
                ob->query("dex"));
                
                sp += sprintf(HIW "�� �� ò �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]   \n",
                ob->query_per(),
                ob->query("per"));

                sp += sprintf(HIW "�� �� Ե �� " NOR + WHT " [%3d]    ["
                      HIG "%3d" NOR + WHT "]   \n",
                ob->query_kar(),
                ob->query("kar"));
                
                sp += HIC "��" HIY "����������������������������������������������"
                      "����������������" HIC "��\n" NOR;
                tell_object(me, sp);
                return 1;
        }

        if (! arg)
                ob = me;
        else
        if (wizardp(me) || me->query("couple/couple_id") || me->query("private_room"))
        {
                ob = present(arg, environment(me));
                if (! ob || (! ob->is_character() && ! ob->is_owner(me))) ob = find_player(arg);
                if (! ob || (! ob->is_character() && ! ob->is_owner(me))) ob = find_living(arg);
                if (! ob || (! ob->is_character() && ! ob->is_owner(me)) || ! me->visible(ob))
                        return notify_fail("��Ҫ�쿴˭��״̬��\n");

                if (! wizardp(me) && me->query("couple/couple_id") != ob->query("id") &&
                    ! ob->is_owner(me))
                        return notify_fail("��Ҫ�쿴˭��״̬��\n");
        } else
                return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

        my = ob->query_entire_dbase();

//        if (userp(ob) && (! stringp(my["born"]) || ! my["born"]))
//                return notify_fail("��û�г����ţ��쿴ʲô��\n");

//        if (my["max_jing"] < 1 || my["max_qi"] < 1)
//                return notify_fail("�޷��쿴" + ob->name(1) + "��״̬��\n");
i=(ceil(pow(ob->query("combat_exp")*10.0, 0.444444)) + 100)*500;	
if (userp(ob))
{
if (ob->query("jingli")<0) ob->set("jingli",0);
}
        sp = (ob == me ? "��" : ob->name()) + "Ŀǰ��״̬�������£�\n";
        sp += HIC "��" HIY "����������������������������������������������"
              "����������������" HIC "��\n" NOR;

        sp += sprintf(HIC "�� ��  �� �� %s%5d/ %5d %s(%3d%%)"
                      HIC "    �� ��  �� �� %s%5d / %5d (+%d)\n",
                status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),
                             my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["jingli"], my["max_jingli"]), my["jingli"],
                             my["max_jingli"], my["jiajing"] );

        sp += sprintf(HIC "�� ��  Ѫ �� %s%5d/ %5d %s(%3d%%)"
                      HIC "    �� ��  �� �� %s%5d / %5d (+%d)\n",
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]),
                              my["eff_qi"] * 100 / my["max_qi"],
                status_color(my["neili"], my["max_neili"]), my["neili"],
                             my["max_neili"], my["jiali"] );

        sp += sprintf(HIW "�� ʳ  �� �� %s%5d/ %5d      " HIW "     �� Ǳ  �� ��  %d (%d)\n",
                status_color(my["food"], ob->max_food_capacity()),
                my["food"], ob->max_food_capacity(),
                (int)ob->query("potential") - (int)ob->query("learned_points"),
                i);
if (my["shen"] < 0)
{
        sp += sprintf(HIW "�� ��  ˮ �� %s%5d/ %5d      " HIR "     �� ��  �� ��  %d\n",
                status_color(my["water"], ob->max_food_capacity()),
                my["water"], ob->max_food_capacity(),
                -1*my["shen"]);
}
else
{
        sp += sprintf(HIW "�� ��  ˮ �� %s%5d/ %5d      " HIC "     �� ��  �� ��  %d\n",
                status_color(my["water"], ob->max_food_capacity()),
                my["water"], ob->max_food_capacity(),
               my["shen"]);
}

  i=ob->query_skill("force")*15 + (ob->query("szj/passed")?ob->query_skill("shenzhao-jing",1)*4:0);              
 i1=ob->query_skill("force")*15 + (ob->query("szj/passed")?ob->query_skill("shenzhao-jing",1)*4:0);              
        sp += sprintf(HIW "�� ��  �� �� %20d" HIC "   ���������ޡ�  %d \n",
                my["combat_exp"],
i);
      
        //sp += sprintf(HIW "�� �� �� ��  " HIC "%d\n", my["combat_exp"]);
        sp += HIC "��" HIY "����������������������������������������������"
              "����������������" HIC "��\n" NOR;
        tell_object(me, sp);
        return 1;
}
 
string status_color(int current, int max)
{
        int percent;
 
        if (max > 0)
                percent = current * 100 / max;
        else
                percent = 100;

        if (percent > 100) return HIC;
        if (percent >= 90) return HIG;
        if (percent >= 60) return HIY;
        if (percent >= 30) return YEL;
        if (percent >= 10) return HIR;
        return RED;
}
 
int help(object me)
{
        write(@HELP
ָ���ʽ��hp [-g]
          hp [-g] <��������>               ����ʦר�ã�

���ָ�������ʾ���ָ������ľ�����������ֵ�������� -g �������
��ϸ���г�����츳����״̬��

���ָ�score
HELP);
        return 1;
}
                   