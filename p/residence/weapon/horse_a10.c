#include <ansi.h> 
#include <armor.h>

inherit WAIST;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[33mҹ��֮����[2;37;0m", ({ "yecha waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[33mҹ��֮����[2;37;0m����һ�����ޱȼ�Ӳ��[1;33m����[2;37;0m����[32m���˿[2;37;0m�Ƴɣ�������һ����Ǯ��[33mҹ��֮����[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �������ޱȼ�̣�����[36m��С[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;31m��˫[2;37;0m [31m��[2;37;0m:[1;31m��˫[2;37;0m [1;35m��[2;37;0m:[35m��׼[2;37;0m 
[1;37m��[2;37;0m:[1;31m��˫[2;37;0m [1;34m��[2;37;0m:[1;33m��ʥ[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m��Ԫ[2;37;0m ����:[36m����[2;37;0m 
��ʯ:[32m�ֲ�[2;37;0m ��ʯ:[33m�ܸ�[2;37;0m ����:[35m��׼[2;37;0m 
����:[32m�ֲ�[2;37;0m ����:[35m��׼[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mС��[2;37;0m ������һЩ�� [1;32m�Ʒ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "horse");
		set("ownername", "С��");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 39);
    set("armor_prop/parry", 41);
    set("armor_prop/attack", 54);


    set("armor_prop/armor", 194);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 32);
    set("armor_prop/qi", 34);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 32);
    set("armor_prop/damage", 163);

    set("wtypeA",12);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",12);
    set("wtypeE",4);
    set("wtypeF",5);
    set("wtypeG",12);
    set("wtypeH",10);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",3);
    
    
                set("skill", ([
                        "name": "strike",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";