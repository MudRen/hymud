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
	      set_name("[1;33m·ÉÌìÑü´ø[2;37;0m", ({ "shengxie waist", "waist" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
[31mÊ¤Ğ°ÍşÁ¦¾Ş´ó¶øÎŞÈÎºÎÒªÇó£¡
[2;37;0mÕâÊÇÒ»ÌõÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0m¼ÓÉÏ[1;33mÁú¼ë²ÏË¿[2;37;0mÖÆ³É£¬ÖØ¶ş½ïÆßÁ½ÁãÇ®µÄ[31mÊ¤Ğ°Ö®Ñü´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[1;33mÃğÊÀ[2;37;0m [36mÄ¾[2;37;0m:[1;36mÍêÃÀ[2;37;0m [32mË®[2;37;0m:[1;35m¾øÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;33mÌìÊ¥[2;37;0m [1;35m·ç[2;37;0m:[1;35m¾øÊÀ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ¸£Ô´:[32m´Ö²Ú[2;37;0m 
ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
ÉÁµç:[1;34m¾ÙÊÀ[2;37;0m 
³¤Éú:[35m±ê×¼[2;37;0m ²»ÀÏ:[32m´Ö²Ú[2;37;0m ÍşÁ¦:[1;34m¾ÙÊÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m·Éºü[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m´¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "feihu");
		set("ownername", "·Éºü");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",72);
		set("armor_prop/karey",39);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 83);


    set("armor_prop/armor", 502);
    set("armor_prop/defense", 72);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 55);
    set("armor_prop/jing", 37);
    set("armor_prop/jingli", 37);
    set("armor_prop/damage", 343);

    set("wtypeA",0);
    set("wtypeB",7);
    set("wtypeC",11);
    set("wtypeD",0);
    set("wtypeE",10);
    set("wtypeF",11);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",16);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 25);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";