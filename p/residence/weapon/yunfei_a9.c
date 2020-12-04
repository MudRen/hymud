#include <ansi.h> 
#include <armor.h>

inherit ARMOR;

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
	      set_name("[1;36m²ÔÔÆÖ®Åû·ç[2;37;0m", ({ "gongbu armor", "armor" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼ş");
		set("long", @LONG
[31m¹¤²¼ÌìÉú¹ÖÒì£¬¹¦ÄÜ²ÎÉÌ£¡
[2;37;0mÕâÊÇÒ»¼şÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0m¼ÓÉÏ[1;33mÁú¼ë²ÏË¿[2;37;0mÖÆ³É£¬ÖØÈı½ïÒ»Á½ÁãÇ®µÄ[31m¹¤²¼Ö®Åû·ç[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[40mµØ[2;37;0m:[1;32mÄ§Íõ[2;37;0m [33mÍÁ[2;37;0m:[1;33mÃğÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;31m¿ªÔª[2;37;0m 
[1;37mÀ×[2;37;0m:[1;33mÃğÊÀ[2;37;0m [1;34mµç[2;37;0m:[1;33mÃğÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[33mºÜ¸ß[2;37;0m 
×ÏÊ¯:[32m´Ö²Ú[2;37;0m ÉÁµç:[35m±ê×¼[2;37;0m 
³¤Éú:[1;36mÍêÃÀ[2;37;0m ²»ÀÏ:[33mºÜ¸ß[2;37;0m ÍşÁ¦:[1;34m¾ÙÊÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mÔÆ·É[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mÕÈ·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "yunfei");
		set("ownername", "ÔÆ·É");
		set("value", 36000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 36);
    set("armor_prop/attack", 72);


    set("armor_prop/armor", 417);
    set("armor_prop/defense", 72);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 70);
    set("armor_prop/jing", 44);
    set("armor_prop/jingli", 44);
    set("armor_prop/damage", 254);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",16);
    set("wtypeF",13);
    set("wtypeG",16);
    set("wtypeH",16);
    set("wtypeI",0);
    set("wtypeJ",9);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "staff",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 20);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";