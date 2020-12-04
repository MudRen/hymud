#include <ansi.h>
#include <i2d.h>

#ifndef INTERMUD2_D
#define INTERMUD2_D    "/adm/daemons/intermud2_d"
#endif

inherit F_CLEAN_UP;

string help = @HELP
        ��׼ mudlist ָ�
HELP;

int online;

string cstatus(int status, string color)
{
        string str="";

        str += status & ENCODE_CONFIRM  ? HIY"Cf"NOR+color+"|" : YEL"Cf"NOR+color+"|";
        str += status & GB_CODE         ? HIG"GB"NOR+color+"|" : GRN"GB"NOR+color+"|";
        str += status & ANTI_AD         ? HIR"AD"NOR+color+"|" : RED"AD"NOR+color+"|";
        str += status & IGNORED         ? HIB"Ig"NOR+color+"|--" : BLU"Ig"NOR+color+"|--";

        if( status & ONLINE)
        {
                str+=HIW"����"NOR;
                online++;
        }
        if( status&SHUTDOWN)    str+=YEL"�ر�"NOR;
        if( status&DISCONNECT)  str+=WHT"����"NOR;
        str += color;

        return sprintf("%-18s",str);

}

int main(object me, string arg)
{
        mapping mudlist,incoming_mudlist,d,z=([]),x=([]);
        object i2;
        string str="",t;
        string color="",output="";
        mixed c=({}),v=({});

        if( !i2=find_object(INTERMUD2_D) )
                return tell_object(me, "��·���鲢û�б����롣\n");

        if( arg )
        {
                mapping m = i2->query_mudlist()+i2->query_incoming_mudlist();
                string *msg;
                if( msg = i2->fetch_mudname(arg,1) )
                {
                        foreach(string a in msg)
                        printf("%O\n",m[a]);
                        tell_object(me, "ok\n");
                }
                else tell_object(me, "no such mud !\n");
           return 1;
        }

        mudlist = i2->query_mudlist();
        incoming_mudlist= i2->query_incoming_mudlist();

        foreach(t,d in mudlist)
        if(!undefinedp(z[d["NAME"]]))
        {
                if( typeof(z[d["NAME"]])=="array" )
                        z[d["NAME"]]=z[d["NAME"]]+({t});
                else    z[d["NAME"]]=({z[d["NAME"]] })+({t});
        }
        else    z[d["NAME"]]=t;

        foreach(t,d in incoming_mudlist)
        x[d["NAME"]]=t;

        c=keys(z);
        c = sort_array(c,1);
        v=keys(x);
        v = sort_array(v,1);

        str+="��INTERMUD_2 MUDLIST\n\n"HIY"Cf"NOR"-ϵͳ�ɹ��Զ��жϱ�������\n"HIG"GB"NOR"-ȷ��ΪGB����\n"HIR"AD"NOR"-ȷ���д������ѶϢ\n"HIB"Ig"NOR"-����ѶϢ\n\n";
        str+=sprintf("����ʱ�̣�%s\n\n��ȷ����פ�б�\n%-:20s%-26s%16s%5s %18s %-16s\n",TIME_D->replace_ctime(time()),"����","��������(��������)","IP λַ","��","״̬","���Ӵ�");
        str+=repeat_string("��",53)+"\n";
        foreach(t in c)
        {
//              shout(sprintf("%s       \n",t));
                if( typeof(z[t])=="array" )
                {
                        foreach(mixed tmp in z[t])
                        {
                                output="";
                                if(time()-mudlist[tmp]["LASTESTCONTACT"] > 24*60*60 ) color=HIR;
                                else color="";
                                if( mudlist[tmp]["STATUS"] & GB_CODE || undefinedp(mudlist[tmp]["ENCODING"]) || (!undefinedp(mudlist[tmp]["ENCODING"]) && lower_case(mudlist[tmp]["ENCODING"]))=="gb")
                                        str+=sprintf("%s%-:20s%-26s%16s%5s %18s %-16s\n"NOR,
                                                output,t,(mudlist[tmp]["MUDNAME"]||"")+NOR+output+(mudlist[tmp]["USERS"]?"("+mudlist[tmp]["USERS"]+")":""),mudlist[tmp]["HOSTADDRESS"],mudlist[tmp]["PORT"]+"",cstatus(mudlist[tmp]["STATUS"],output),color+TIME_D->replace_ctime(mudlist[tmp]["LASTESTCONTACT"]));
                                else
                                        str+=sprintf("%s%-:20s%-26s%16s%5s %18s %-16s\n"NOR,
                                                output,(string)LANGUAGE_D->toGB(t),(mudlist[tmp]["MUDNAME"]?(string)LANGUAGE_D->toGB(mudlist[tmp]["MUDNAME"]):"")+NOR+output+(mudlist[tmp]["USERS"]?"("+mudlist[tmp]["USERS"]+")":""),mudlist[tmp]["HOSTADDRESS"],mudlist[tmp]["PORT"]+"",cstatus(mudlist[tmp]["STATUS"],output),color+TIME_D->replace_ctime(mudlist[tmp]["LASTESTCONTACT"]));
                        }
                }

                else
                {
                        output="";
                        if(time()-mudlist[z[t]]["LASTESTCONTACT"]> 24*60*60 ) color=HIR;
                        else color="";
                        if( mudlist[z[t]]["STATUS"]& GB_CODE || undefinedp(mudlist[z[t]]["ENCODING"]) || (!undefinedp(mudlist[z[t]]["ENCODING"]) && lower_case(mudlist[z[t]]["ENCODING"])=="gb"))
                                str+=sprintf("%s%-:20s%-26s%16s%5s %18s %-16s\n"NOR,
                                        output,t,(mudlist[z[t]]["MUDNAME"]||"")+NOR+output+(mudlist[z[t]]["USERS"]?"("+mudlist[z[t]]["USERS"]+")":""),mudlist[z[t]]["HOSTADDRESS"],mudlist[z[t]]["PORT"]+"",cstatus(mudlist[z[t]]["STATUS"],output),color+TIME_D->replace_ctime(mudlist[z[t]]["LASTESTCONTACT"]));
                        else
                                str+=sprintf("%s%-:20s%-26s%16s%5s %18s %-16s\n"NOR,
                                        output,(string)LANGUAGE_D->toGB(t),(mudlist[z[t]]["MUDNAME"]?(string)LANGUAGE_D->toGB(mudlist[z[t]]["MUDNAME"]):"")+NOR+output+(mudlist[z[t]]["USERS"]?"("+mudlist[z[t]]["USERS"]+")":""),mudlist[z[t]]["HOSTADDRESS"],mudlist[z[t]]["PORT"]+"",cstatus(mudlist[z[t]]["STATUS"],output),color+TIME_D->replace_ctime(mudlist[z[t]]["LASTESTCONTACT"]));
                }

        }

        str+=repeat_string("��",53)+"\n�� "+sizeof(mudlist)+" �����ϣ��� "+online+" �� Mud �����С�\n\n���ȴ�ȷ���б�\n";
        str+=sprintf("%-:20s%-26s%16s%5s %18s %-16s\n","����","��������(��������)","IP λ��","��","��Ӧ","���Ӵ�");
        str+=repeat_string("��",53)+"\n";
        foreach(t in v)
        str+=sprintf("%-:20s%-26s%16s%5s %18d %-16s\n",t,(incoming_mudlist[x[t]]["MUDNAME"]||"")+NOR+(incoming_mudlist[x[t]]["USERS"]?"("+incoming_mudlist[x[t]]["USERS"]+")":""),incoming_mudlist[x[t]]["HOSTADDRESS"],incoming_mudlist[x[t]]["PORT"]+"",incoming_mudlist[x[t]]["CONNECTION"],TIME_D->replace_ctime(incoming_mudlist[x[t]]["LASTESTCONTACT"]));
        str+=repeat_string("��",53)+"\n�� "+sizeof(incoming_mudlist)+" �����ϣ��´���Ѷ����:"+TIME_D->replace_ctime(i2->query_refresh_limit()+REFRESH_INCOMING_TIME)+"\n\n�ܼƹ� "+sizeof(mudlist+incoming_mudlist)+" �� Mud ��\n";

        online=0;


        me->start_more(str);

        return 1;
}
