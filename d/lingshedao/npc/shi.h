#include <ansi.h>
int fight3(object ob)
{
string* names = ({
        "miao feng",
        "hui yue",
        "liu yun",
});

        object who;
        object aa=this_object();
        object tld;
        object room3;
        object room4;

        int i;
        int j;
        int k;
                who=ob;
      for(j=1;j<=3;j++)
      {        
        if(!( room3 = find_object("/d/lingshedao/xiaowu")) )
            room3 = load_object("/d/lingshedao/xiaowu");
        if( objectp(aa = present(names[j-1], room3) ))
        aa=present(names[j-1],room3);
        for(i=0;i<6;i++)
        {
if (!aa) return 1;
if (!ob) return 1;
        say(HIR""+aa->query("name")+"���һ�������У�"NOR);
        COMBAT_D->do_attack(aa, ob, query_temp("weapon"));
        if( (int)ob->query("qi") < 100)
             break;
        ob->add_temp("3beat",1);
        }
      }  
        if( (int)ob->query("qi") < 100)
      {
        message_vision(HIC"����ʹ��м�Ķ�$N˵:����㹦��,������Ӳ.\n\n"NOR,ob);
        if(objectp(present("tulong dao",ob)) )
        {message_vision(HIC"˵������ʹ��$N���е����������˹�ȥ.\n\n",ob);
        tld=present("tulong dao",ob);
        tld->move(aa);}
        return 1;
      } 
        if((int)ob->query("qi")>=200&&(int)ob->query_temp("3beat")>=18)
      {
        message_vision(HIC"����ʹ˵��:������Ȼ���˲�,������!˵�����˷�����ȥ.\n\n"NOR,ob);
  if((int)who->query("jinyong/book12")==5)
{
		i = 1350+random(2000);
		who->set("jinyong/book12",6);
		who->add("combat_exp",i+15000);
		who->add("potential",i*25);
		who->add("mpgx",10);
		who->add("expmax",2);
		tell_object (who,"��Ӯ����"+chinese_number(i+15000)+"�㾭��"+
		           chinese_number(i*25)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");

		who->save();
}


        if(!room4=find_object("/d/lingshedao/chuan"))
        room4=load_object("/d/lingshedao/chuan");
        for(k=1;k<=3;k++)
         {
          if( objectp(aa = present(names[k-1], environment(ob)) ))
 //               aa=present(names[k-1],"/d/lingshedao/xiaowu");        
//                aa->move(room4);
              destruct(aa);
         }
        ob->add("combat_exp",50000);
        ob->delete_temp("3beat");
        return 1;
      }
       return 1;
}
int dest(object ob)
{
string* names = ({
        "miao feng",
        "hui yue",
        "liu yun",
});

        object aa=this_object();
        object tld;
        object room3;
        object room4;
        int i;
        int j;
        int k;
        message_vision(HIC"����ʹ˵��:����������,������!˵�����˷�����ȥ.\n\n"NOR,ob);
        for(k=1;k<=3;k++)
         {
          if( objectp(aa = present(names[k-1], environment(ob)) ))
              destruct(aa);
         }
       return 1;
}