//crack by stey

inherit ROOM;

void check_zuochan(object me);
void finish(object me);

string chinese_time(int timep);

string *str=({
                "����������������\n",
                "�����һ��ʤ�����趼�ǹ������̡�\n",
                "������Լ�������һ��ǰ��δ�еľ��硣\n",
                "����ľ�����������\n"
                "�����������򵽷�ľ��衣\n",
                "���˼����������������\n"
             });

void create ()
{
  set ("short", "����");
  set ("long", @LONG
����յ����ģ�ֻ�ڿ���ǽ�ڵĵط���������ط���һЩ���š�
������ߺܰ���ǽ�ڲ�֪����ʲô�������ģ��ᷢ�������Ļ�
�⡣����������(zuochan)����ĺõط�����Ҫ��ʵ�ڶ�������
Ҳ���Գ�ȥ�����ٻ���(halt)��

LONG);

  set("exits", ([
          "south"   : __DIR__"baoge1",
      ]));

  set("no_fight", 1);
  set("no_time",1);
  set("no_magic", 1);
  setup();
}

void init()
{
    add_action("do_zuochan", "zuochan");
    add_action("do_halt", "halt");
}

int do_zuochan()
{       int zuochan_time;

        object me = this_player();

        if (me->query("rulaitask/get"))
             {tell_object(me,"��������������������������\n");
              return 1;
             }

        if (me->query_temp("zuochan"))
             {tell_object(me,"��������������\n");
              return 1;
             }

        message_vision("$N��ϥ����һ�������ϣ�Ǳ˼�붨����ʼ�����Լ���������Ϊ��\n",me);
        me->set_temp("no_move", 1);
        me->set_temp("zuochan", 1);
        if ( !me->query("rulaitask") )  finish(me);
        else {
                if (me->query("rulaitask/fail"))
                zuochan_time = 30+random(16);
                else zuochan_time = 10+random(16);
                me->set_temp("zuochan_time",zuochan_time);

                check_zuochan(me);
              }

        return 1;
}


void check_zuochan(object me)
{
        int zuochan_time = me->query_temp("zuochan_time");

           if (!me->query_temp("zuochan")) return;

        if ( zuochan_time <= 0 ) finish(me);

        else {
                if ( zuochan_time%6 == 0 )
                      tell_object(me,str[random(sizeof(str))]);
                me->add_temp("zuochan_time", -1);
             me->add_busy(1);
                call_out("check_zuochan",1,me);
              }
}


void finish(object me)
{
        tell_object(me,"��ֻ����̨һƬ�������ƺ������Ѿ���\n");
        message_vision("$N��������˿�����վ��������\n",me);
        me->delete_temp("no_move");
        me->delete_temp("zuochan");
        me->delete("rulaitask");
        me->set("rulaitaskjob/done",1);
}



int do_halt()
{
        object me = this_player();

          me->add_busy(3);
        if(me->query_temp("last_halt_time") && !wizardp(me) && (me->query_temp("last_halt_time")+20)>time())
        {
                tell_object(me,"�ȵ�......\n");
                return 1;
        }
        me->add("jing",-10);
        me->set_temp("last_halt_time",time());
        if (me->query_temp("zuochan"))
        {
//274                  remove_call_out("check_zuochan");
                me->delete_temp("zuochan_time");
                message_vision("$N��������˿�����վ��������\n",me);
                me->delete_temp("no_move");
                me->delete_temp("zuochan");
                return 1;
        }
        else return 0;
}



string chinese_time(int timep)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        return time;
}


