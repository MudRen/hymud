#include <ansi.h> 
#include <armor.h>

inherit SURCOAT;

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
	      set_name("[1;31mÎ´Ñë[2;37;0m", ({ "xuanyuan surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
[1;35mÎôÈÕ»ÆµÛ³Ö´ËÎïÁ¢ÓÚÖ¸ÄÏ³µÉÏ£¬ÇıÃÔÎí£¬É¨Òõö²£¬ÂÊÓ¦Áúºµ÷É£¬Óù°ÙÊŞ¶øÕ½ò¿ÓÈ£¡
[2;37;0mÕâÊÇÒ»ÌõÓÉÏàµ±¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[37mÌì²ÏË¿[2;37;0mÖÆ³É£¬ÖØÒ»½ï¾ÅÁ½°ËÇ®µÄ[1;35mĞùÔ¯Ö®¶Ç´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´Ïàµ±¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;31m¿ªÔª[2;37;0m [32mË®[2;37;0m:[1;31m¿ªÔª[2;37;0m [33mÍÁ[2;37;0m:[35m±ê×¼[2;37;0m [1;35m·ç[2;37;0m:[1;32mÄ§Íõ[2;37;0m 

ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
³¤Éú:[1;36mÍêÃÀ[2;37;0m ²»ÀÏ:[35m±ê×¼[2;37;0m ÍşÁ¦:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32m»¨ÎŞÀâ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕĞ¼Ü[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "enjoy");
		set("ownername", "»¨ÎŞÀâ");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",40);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 284);
    set("armor_prop/defense", 32);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 70);
    set("armor_prop/jing", 58);
    set("armor_prop/jingli", 58);
    set("armor_prop/damage", 186);

    set("wtypeA",13);
    set("wtypeB",6);
    set("wtypeC",13);
    set("wtypeD",6);
    set("wtypeE",5);
    set("wtypeF",9);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",6);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "parry",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";