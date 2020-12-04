#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[1;32m�޼�֮����[2;37;0m", ({ "wuji hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;32m�����Ѵ�����뻯���Ƿ��켫���������֮���磡��˵������ڣ������⡰�޼�����
[2;37;0m����һ�����ޱȼ�Ӳ��[37m����[2;37;0m����[37m���˿[2;37;0m�Ƴɣ������������Ǯ��[1;32m�޼�֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������ޱȼ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[36mľ[2;37;0m:[35m��׼[2;37;0m [32mˮ[2;37;0m:[1;32mħ��[2;37;0m [31m��[2;37;0m:[1;31m��Ԫ[2;37;0m [1;35m��[2;37;0m:[1;32mħ��[2;37;0m 

���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ����:[33m�ܸ�[2;37;0m 
��ʯ:[33m�ܸ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
����:[35m��׼[2;37;0m ����:[35m��׼[2;37;0m ����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m���[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lingdy");
		set("ownername", "���");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",56);
		set("armor_prop/karey",48);
		set("armor_prop/percao",56);
		set("armor_prop/dexerity",40);
		set("armor_prop/constitution",56);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 56);


    set("armor_prop/armor", 648);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 52);
    set("armor_prop/qi", 57);
    set("armor_prop/jing", 56);
    set("armor_prop/jingli", 56);
    set("armor_prop/damage", 1336);

    set("wtypeA",5);
    set("wtypeB",5);
    set("wtypeC",9);
    set("wtypeD",13);
    set("wtypeE",6);
    set("wtypeF",9);
    set("wtypeG",7);
    set("wtypeH",6);
    set("wtypeI",5);
    set("wtypeJ",6);
    set("wtypeK",7);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "axe",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";